#ifndef CIPHER_H
#define CIPHER_H

#include <QDebug>

#include <openssl/engine.h>
#include <openssl/conf.h>
#include <openssl/aes.h>

#define KEYSIZE 32 // Размер ключа в байтах
#define IVSIZE 32 //
#define BLOCKSIZE 256
#define SALTSIZE 8

class Cipher
{
public:
    Cipher();
    ~Cipher();

    QByteArray encryptAES(QByteArray passphrase, QByteArray &data);
    QByteArray decryptAES(QByteArray passphrase, QByteArray &data);

private:
    QByteArray randomBytes(int size);
};

#endif // CIPHER_H
