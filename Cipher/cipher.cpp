#include "cipher.h"

// Инициализация класса шифрования
Cipher::Cipher()
{
    ERR_load_CRYPTO_strings(); // Регистрация строк ошибок
    OpenSSL_add_all_algorithms(); // Добавляет алгоритмы
    OPENSSL_config(nullptr);
}

// Деструктор класса шифрования
Cipher::~Cipher()
{
    ERR_free_strings();
    EVP_cleanup(); // Добавление алгоритмов во внутреннюю таблицу
}

// Генератор рандомных байтов
QByteArray Cipher::randomBytes(int size)
{
    unsigned char * arr = new unsigned char[size];
    RAND_bytes(arr, size);

    QByteArray buffer = QByteArray(reinterpret_cast<char *>(arr), size);
    return buffer;
}

QByteArray debugCritical(QString msg)
{
    qCritical() << msg << ERR_error_string(ERR_get_error(), nullptr);
    return QByteArray();
}




/**
 * @brief Шифровка данных
 * @param passphrase - Ключ шифрования
 * @param data - Данные для шифровки
 * @return Шифрованные данные
 */
QByteArray Cipher::encryptAES(QByteArray passphrase, QByteArray &data)
{
    QByteArray msalt = randomBytes(SALTSIZE); // Создаем соль (рандом)
    int rounds = 1; // Кол-во прохождений
    unsigned char key[KEYSIZE]; // Переменная для ключа
    unsigned char iv[IVSIZE]; // Переменная для инициализирующего вектора

    const unsigned char * salt = reinterpret_cast<const unsigned char *>(msalt.constData()); // Перевод соли с unsigned char*
    const unsigned char * password = reinterpret_cast<const unsigned char *>(passphrase.constData()); // Перевод ключа с unsigned char*

    int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, password, passphrase.length(), rounds, key, iv); // Формирование ключа относительно входящих данных

    if (i != KEYSIZE) // Проверяет корректность генерации ключа
        return debugCritical("EVP_BytesToKey() error: ");

    EVP_CIPHER_CTX en; // Структура шифрования
    EVP_CIPHER_CTX_init(&en); // Создание структуры шифрования

    if (!EVP_EncryptInit_ex(&en, EVP_aes_256_cbc(), nullptr, key, iv)) // Устанавливает контекст шифрования с заданным типом шифрования
        return debugCritical("EVP_EncryptInit_ex() failed ");

    char * input = data.data(); // Переводит QByteArray в char *
    int len = data.size(); // Размер исходных данных
    int c_len = len + AES_BLOCK_SIZE; // Предполагаемый размер шифрованных данных с запасом ( при разбиении данных на блоки возможно зашифрованные данные будут большего размера, чем исходные )
    int f_len = 0; // Финальный размер зашифрованных данных
    unsigned char * ciphertext = new unsigned char[c_len]; // Хранилище зашифрованных данных

    if (!EVP_EncryptInit_ex(&en, nullptr, nullptr, nullptr, nullptr)) // Инициализация шифрования
        return debugCritical("EVP_EncryptInit_ex() failed ");

    if (!EVP_EncryptUpdate(&en, ciphertext, &c_len, reinterpret_cast<unsigned char *>(input), len)) // Шифрование блоков без частичного (последнего) блока
        return debugCritical("EVP_EncryptUpdate() failed ");

    if (!EVP_EncryptFinal(&en, ciphertext + c_len, &f_len)) // Шифрование частичного блока
        return debugCritical("EVP_EncryptFinal() failed ");

    len = c_len + f_len; // Суммируется то, что сформировалось в update и final
    EVP_CIPHER_CTX_cipher(&en);

    QByteArray encrypted = QByteArray(reinterpret_cast<char *>(ciphertext), len); // Зашифрованные данные в encrypted

    QByteArray finished; // Зашифрованные данные с солью
    finished.append("Salted__");
    finished.append(msalt); // Добавление соли
    finished.append(encrypted); // Добавление зашифрованных данных

    free(ciphertext); // Освобождение памяти

    return finished; // Возврат
}

// Дешифровка AES
QByteArray Cipher::decryptAES(QByteArray passphrase, QByteArray &data)
{
    QByteArray msalt; // Переменная, хранящая соль
    if (QString(data.mid(0, 8)) == "Salted__") // Указание на содержание соли
    {
        msalt = data.mid(8, SALTSIZE); // Подстрока
        data = data.mid(8 + SALTSIZE); // Подстрока
    }
    else {
        qWarning() << "Could not load salt from data!";
        msalt = randomBytes(SALTSIZE); // Рандомный генератор соли
    }

    int rounds = 1; // Кол-во прохождений
    unsigned char key[KEYSIZE]; // Переменная для ключа
    unsigned char iv[IVSIZE]; // Переменная для инициализирующего вектора
    const unsigned char * salt = reinterpret_cast<const unsigned char *>(msalt.constData()); // Перевод соли с unsigned char*
    const unsigned char * password = reinterpret_cast<const unsigned char *>(passphrase.data()); // Перевод ключа с unsigned char*

    int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, password, passphrase.length(), rounds, key, iv); // Формирование ключа относительно входящих данных

    if (i != KEYSIZE)
        return debugCritical("EVP_BytesToKey() error: "); // Проверяет корректность генерации ключа

    EVP_CIPHER_CTX de; // Структура дешифрования
    EVP_CIPHER_CTX_init(&de);  // Создание структуры дешифрования

    if (!EVP_DecryptInit_ex(&de, EVP_aes_256_cbc(), nullptr, key, iv))
        return debugCritical("EVP_DecryptInit_ex() failed ");

    char * input = data.data(); // Переводит QByteArray в char *
    char * out; // Размер исходных данных
    int len = data.size();  // Размер исходных данных

    int p_len = len, f_len = 0;
    unsigned char * plaintext = new unsigned char[p_len + AES_BLOCK_SIZE]; // Предполагаемый размер шифрованных данных с запасом ( при разбиении данных на блоки возможно зашифрованные данные будут большего размера, чем исходные )

    if (!EVP_DecryptUpdate(&de, plaintext, &p_len, reinterpret_cast<unsigned char *>(input), len)) // Дешифрование блоков без частичного (последнего) блока
        return debugCritical("EVP_DecryptUpdate() failed ");

    if (!EVP_DecryptFinal_ex(&de, plaintext + p_len, &f_len))
        return debugCritical("EVP_DecryptFinal_ex() failed ");

    len = p_len + f_len; // Суммируется то, что сформировалось в update и final
    out = reinterpret_cast<char *>(plaintext);
    EVP_CIPHER_CTX_cleanup(&de);

    QByteArray decrypted = QByteArray(reinterpret_cast<char *>(plaintext), len); // Окончательный текст в виде QByteArray
    free(plaintext); // Очистить память

    return decrypted;
}

