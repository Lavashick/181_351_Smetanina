#ifndef CIPHER_H
#define CIPHER_H

#include <QDebug>

#include <openssl/engine.h> // Криптографический движок
#include <openssl/conf.h> // Библиотека конфигурационных файлов
#include <openssl/aes.h> // Алгоритм шифрования AES

#define KEYSIZE 32 // Размер ключа в байтах
#define IVSIZE 32 // Размер анациализирующего вектора
#define BLOCKSIZE 256 // Размер блока входных данных
#define SALTSIZE 8 // Размер данных соли

class Cipher
{
public:
    Cipher(); // Конструктор
    ~Cipher(); // Деструктор

    /**
     * @brief Шифровка в AES
     */
    QByteArray encryptAES(QByteArray passphrase, QByteArray &data);
    /**
     * @brief Расшифровка в AES
     */
    QByteArray decryptAES(QByteArray passphrase, QByteArray &data);

private:
    QByteArray randomBytes(int size);
};

#endif // CIPHER_H
