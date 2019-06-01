#include "human.h"

Human::Human(QJsonObject json) {
    this->id = json.value("id").toInt();
    this->firstName = json.value("first_name").toString();
    this->lastName = json.value("last_name").toString();
    this->age = json.value("age").toInt();
}
