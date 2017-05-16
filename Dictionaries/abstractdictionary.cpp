#include "abstractdictionary.h"

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>

AbstractDictionary::AbstractDictionary(const QJsonDocument &doc, QObject *parent)
    : QObject(parent)
{
    initDictionary(doc);
}

QString AbstractDictionary::getTranslation(const QString &word)
{
    return dictionary.value(word);
}

QJsonDocument AbstractDictionary::getJsonDoc(const QString &address)
{
    QFile file(address);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    return QJsonDocument::fromJson(file.readAll());
}

void AbstractDictionary::initDictionary(const QJsonDocument &doc)
{
    QJsonArray arr = doc.array();

    std::for_each(arr.begin(), arr.end(), [this](const QJsonValue& it)
    {
        if(!it.isObject())
            return;

        QJsonObject item = it.toObject();

        QString word = item.value("word").toString();
        QString translation = item.value("translation").toString();
        dictionary.insert(word, translation);
        qDebug() << word << translation;
    });
}
