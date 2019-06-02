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
    unsigned char arr[size];
    RAND_bytes(arr, size);

    QByteArray buffer = QByteArray(reinterpret_cast<char *>(arr), size);
    return buffer;
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

    int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, password, passphrase.length(), rounds, key, iv);

    if (i != KEYSIZE)
    {
        qCritical() << "EVP_BytesToKey() error: " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    EVP_CIPHER_CTX en;
    EVP_CIPHER_CTX_init(&en);

    if (!EVP_EncryptInit_ex(&en, EVP_aes_256_cbc(), nullptr, key, iv))
    {
        qCritical() << "EVP_EncryptInit() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    char * input = data.data();
    char * out;
    int len = data.size();
    int c_len = len + AES_BLOCK_SIZE, f_len = 0;
    unsigned char * ciphertext = (unsigned char *)malloc(c_len);

    if (!EVP_EncryptInit_ex(&en, nullptr, nullptr, nullptr, nullptr))
    {
        qCritical() << "EVP_EncryptInit_ex() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    if (!EVP_EncryptUpdate(&en, ciphertext, &c_len, (unsigned char *)input, len))
    {
        qCritical() << "EVP_EncryptUpdate() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    if (!EVP_EncryptFinal(&en, ciphertext + c_len, &f_len))
    {
        qCritical() << "EVP_EncryptFinal() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    len = c_len + f_len;
    out = (char *)ciphertext;
    EVP_CIPHER_CTX_cipher(&en);

    QByteArray encrypted = QByteArray(reinterpret_cast<char *>(ciphertext), len);
    QByteArray finished;
    finished.append("Salted__");
    finished.append(msalt);
    finished.append(encrypted);

    free(ciphertext);

    return finished;
}






// Дешифровка AES
QByteArray Cipher::decryptAES(QByteArray passphrase, QByteArray &data)
{
    QByteArray msalt;
    if (QString(data.mid(0, 8)) == "Salted__")
    {
        msalt = data.mid(8, 8);
        data = data.mid(16);
    }
    else {
        qWarning() << "Could not load salt from data!";
        msalt = randomBytes(SALTSIZE);
    }

    int rounds = 1;
    unsigned char key[KEYSIZE];
    unsigned char iv[IVSIZE];
    const unsigned char * salt = (const unsigned char *)msalt.constData();
    const unsigned char * password = (const unsigned char *)passphrase.data();

    int i = EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), salt, password, passphrase.length(), rounds, key, iv);

    if (i != KEYSIZE)
    {
        qCritical() << "EVP_BytesToKey() error: " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    EVP_CIPHER_CTX de;
    EVP_CIPHER_CTX_init(&de);

    if (!EVP_DecryptInit_ex(&de, EVP_aes_256_cbc(), nullptr, key, iv))
    {
        qCritical() << "EVP_DecryptInit_ex() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    char * input = data.data();
    char * out;
    int len = data.size();

    int p_len = len, f_len = 0;
    unsigned char * plaintext = (unsigned char *)malloc(p_len + AES_BLOCK_SIZE);

    if (!EVP_DecryptUpdate(&de, plaintext, &p_len, (unsigned char *)input, len))
    {
        qCritical() << "EVP_DecryptUpdate() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    if (!EVP_DecryptFinal_ex(&de, plaintext + p_len, &f_len))
    {
        qCritical() << "EVP_DecryptFinal_ex() failed " << ERR_error_string(ERR_get_error(), nullptr);
        return QByteArray();
    }

    len = p_len + f_len;
    out = (char *)plaintext;
    EVP_CIPHER_CTX_cleanup(&de);

    QByteArray decrypted = QByteArray(reinterpret_cast<char *>(plaintext), len);
    free(plaintext);

    return decrypted;
}


//QString Chipher::encrypt(QString text)
//{
//    unsigned char *plaintext = getUnsignedCharFromString(text); // исходный текст
//    int plaintext_len = strlen((char *)plaintext); // длина текста
//    unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
//    unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
//    unsigned char cryptedtext[256]; // зашифрованный результат

//    // 1. Создаётся указатель на несуществующую структуру
//    // структура - тип данных в C++, близка к КЛАССУ, различия минимальны
//    EVP_CIPHER_CTX *ctx; // structure

//    // 2. Для указателя создаётся пустая структура настроек (метод, ключ, вектор инициализации и т.д.)
//    ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

//    // 3. Структура EVP_CIPHER_CTX заполняется настройками
//    EVP_EncryptInit_ex(ctx, // ссылка на объект/структуру, куда заносятся параметры
//        EVP_aes_256_cbc(), // ссылка на шифрующее ядро AES 256 (функцию с алгоритмом)
//        NULL,
//        key, // ключ/пароль/секрет
//        iv); // рандомайзер (случайный начальный вектор)

//    // 4. САМ ПРОЦЕСС ШИФРОВАНИЯ - ФУКНЦИЯ EVP_EncryptUpdate
//    int len;
//    EVP_EncryptUpdate(ctx, // объект с настройками
//        cryptedtext, // входной параметр: ссылка, куда помещать зашифрованные данные
//        &len, // выходной параметр: длина полученного шифра
//        plaintext, // входной параметр: что шифровать
//        plaintext_len); // входной параметр : длина входных данных
//    int cryptedtext_len = len;

//    // 5. Финализация процесса шифрования
//    // необходима, если последний блок заполнен данными не полностью
//    EVP_EncryptFinal_ex(ctx, cryptedtext + len, &len);
//    cryptedtext_len += len;

//    // 6. Удаление структуры
//    EVP_CIPHER_CTX_free(ctx);

//    return getStringFromUnsignedChar(cryptedtext);
//}

//QString Chipher::decrypt(QString text)
//{
//    unsigned char * cryptedtext = getUnsignedCharFromString(text); // зашифрованный результат
//    int cryptedtext_len = 10;
//    int len = 10;
//    // РАСШИФРОВКА
//    unsigned char *key = (unsigned char *)"0123456789"; // пароль (ключ)
//    unsigned char *iv = (unsigned char *)"0123456789012345"; // инициализирующий вектор, рандомайзер
//    unsigned char decryptedtext[256]; // расшифрованный результат

//    EVP_CIPHER_CTX *ctx; // structure

//    // 1.
//    ctx = EVP_CIPHER_CTX_new(); // создание структуры с настройками метода

//    // 2.
//    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // инициализация методом AES, ключом и вектором

//    // 3.
//    EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len);  // СОБСТВЕННО, ШИФРОВАНИЕ

//    // 4.
//    int dectypted_len = len;
//    EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len);

//    // 5.
//    dectypted_len += len;
//    EVP_CIPHER_CTX_free(ctx);
//    decryptedtext[dectypted_len] = '\0';
//    cout << decryptedtext << endl;
//    cout << cryptedtext << endl;

//    // --- шифрование файла
//    // производится точно так же, но порциями, в цикле
//    // в цикле
//    /*
//        1) открытие файлов и настройка параметров OpenSSL
//        2) считывание первого блока
//        3) while(считанный_фрагмент > 0)
//        {
//            4) шифрование считанного
//            5) запись зашифрованного массива в файл
//            6) считывание следующего фрагмента
//        }
//        7) применение финализирующей фукнции
//        8) запись финализирующего блока в файл
//        9) закрытие файлов
//    */
//    getchar();
//}
