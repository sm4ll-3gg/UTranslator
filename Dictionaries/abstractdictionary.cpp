#include "abstractdictionary.h"

#include <QDebug>

AbstractDictionary::AbstractDictionary(const QJsonDocument &dictionaryDocument,
                                       QObject *parent)
    : QObject(parent)
{
    constructDictionaryFromJson(dictionaryDocument);
}

AbstractDictionary::Dictionary AbstractDictionary::constructDictionaryFromJson(const QJsonDocument &doc)
{
    qDebug() << doc.isEmpty();
    return Dictionary();
}
