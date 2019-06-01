#include "hash.h"
#include "qbytearrayparcer.h"

static QCryptographicHash::Algorithm hashAlgorithm = QCryptographicHash::Md5;

void Hash::changeHashAlgorithm(QCryptographicHash::Algorithm algorithm) {
    hashAlgorithm = algorithm;
}

QString Hash::start(QString text) {
    QByteArray bytes = QByteArrayParcer::stringToBytes(text);
    QByteArray hashBytes = QCryptographicHash::hash(bytes, hashAlgorithm).toHex();
    return QByteArrayParcer::toString(hashBytes);
}
