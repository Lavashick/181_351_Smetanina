#include "pansionat.h"

Pansionat::Pansionat(QJsonObject json) {
    this->id = json.value("id").toInt();
    this->title = json.value("title").toString();
}
