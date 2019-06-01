#include "city.h"

City::City(QJsonObject json) {
    this->id = json.value("id").toInt();
    this->title = json.value("title").toString();
}
