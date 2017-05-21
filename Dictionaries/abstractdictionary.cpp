#include "abstractdictionary.h"

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QDir>

AbstractDictionary::AbstractDictionary(const QJsonDocument &doc, QObject *parent)
    : QObject(parent)
{
    initDictionary(doc);
}

QString AbstractDictionary::getTranslation(const QString &word)
{
    QString translation = dictionary.value(word);

    return translation == "" ? word : translation;
}

QJsonDocument AbstractDictionary::getJsonDoc(const QString &address)
{
    QFile file(address);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    return QJsonDocument::fromJson(file.readAll());
}

void AbstractDictionary::initDictionary(const QJsonDocument &doc)
{
    qDebug() << doc.isArray();
    QJsonArray arr = doc.array();

    std::for_each(arr.begin(), arr.end(), [this](const QJsonValue& it)
    {
        if(!it.isObject())
            return;

        processJsonObject( it.toObject() );

//        QString word = item.value("word").toString();
//        QString translation = item.value("translation").toString();
//        dictionary.insert(word, translation);
//        qDebug() << word << translation;
    });
}

void AbstractDictionary::processJsonObject(const QJsonObject& word)
{
    QString partOfSpeech = word.value("part of speech").toString();

    if(partOfSpeech == "noun")
        qDebug() << "noun";
    else if(partOfSpeech == "verb")
        qDebug() << "vetb";
    else if(partOfSpeech == "adj")
        qDebug() << "adjective";
    else
        qDebug() << "undefined part of speech";
}
