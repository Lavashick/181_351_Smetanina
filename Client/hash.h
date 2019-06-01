#ifndef HASH_H
#define HASH_H

#include <QCryptographicHash>


/**
 * @brief Работа с хешем
 */
class Hash
{
public:
    /**
     * @brief Изменение стандартного метода хештрования
     */
    static void changeHashAlgorithm(QCryptographicHash::Algorithm algorithm);
    /**
     * @brief Процесс хеширования
     */
    static QString start(QString text);
};

#endif // HASH_H
