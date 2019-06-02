#include <QApplication>
#include "dialog.h"
#include "dbservice.h"
#include "client.h"

#include "cipher.h"

void fillDB() {
    if (DBService::createTableUsers())
    {
        // degree - степень "власти": 3 - user, 2 - moderator, 1 - admin
        DBService::addUser("user", "iamuser", 3);
        DBService::addUser("admin", "iamadmin", 1);
        DBService::addUser("moderator", "iammoderator", 2);
    }

    if (DBService::createTableCities())
    {
        DBService::addCity("Москва");
        DBService::addCity("Нижний Новгород");
        DBService::addCity("Рига");
        DBService::addCity("Новокузнецк");
        DBService::addCity("Саратов");
        DBService::addCity("Тольятти");
        DBService::addCity("Самара");
        DBService::addCity("Нью-Йорк");
    }
    if (DBService::createTablePansionats())
    {
        DBService::createTablePansionatCity();
        DBService::addPansionat("Южный", "Москва");
        DBService::addPansionat("Веселая старость", "Нижний Новгород");
        DBService::addPansionat("Грустная молодость", "Рига");
        DBService::addPansionat("Я не люблю борщи", "Новокузнецк");
        DBService::addPansionat("Пеку пирожки", "Саратов");
        DBService::addPansionat("Лучше гроб", "Тольятти");
        DBService::addPansionat("Жду пенсию", "Самара");
        DBService::addPansionat("Внуки", "Самара");
        DBService::addPansionat("Скоро умирать", "Тольятти");
    }
    if (DBService::createTableHumans())
    {
        DBService::createTableHumanPansionat();
        DBService::addHuman("Стас", "Силиверстов", 95, "Южный");
        DBService::addHuman("Николай", "Зайцев", 49, "Веселая старость");
        DBService::addHuman("Александра", "Милонов", 15, "Грустная молодость");
        DBService::addHuman("Евгения", "Путина", 63, "Я не люблю борщи");
        DBService::addHuman("Тимофей", "Давыдов", 59, "Пеку пирожки");
        DBService::addHuman("Евгений", "Демин", 72, "Лучше гроб");
        DBService::addHuman("Иван", "Иванов", 81, "Жду пенсию");
        DBService::addHuman("Мадина", "Евлеева", 81, "Скоро умирать");
        DBService::addHuman("Ричард", "Второй", 81, "Скоро умирать");
        DBService::addHuman("Леонард", "Васильев", 75, "Скоро умирать");
        DBService::addHuman("Анастасия", "Евсютина", 120, "Скоро умирать");
    }
}

void testAES()
{
    qDebug() << "Tesing AES...";

    Cipher cWrapper;
    QString passphrase = "password";
    QByteArray plain = "The man in black fled into the desert and the gunslinger followed...";

    QByteArray encrypted = cWrapper.encryptAES(passphrase.toLatin1(), plain);
    QByteArray decrypted = cWrapper.decryptAES(passphrase.toLatin1(), encrypted);

    qDebug() << plain;
    qDebug() << encrypted.toBase64();
    qDebug() << decrypted;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    testAES();

    Client::createSocket();
    Client::connectToHost("127.0.0.1", 8181);

    fillDB();

    Dialog d;
    d.show();

    return a.exec();
}
