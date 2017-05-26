#include "abstractdictionary.h"

#include "Words/noun.h"
#include "Words/verb.h"

#include <QDebug>
#include <QFile>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonObject>
#include <QDir>

AbstractDictionary::AbstractDictionary(Language f, Language t,
                                       const QJsonDocument &doc, QObject *parent)
    :QObject(parent),
      from(f), to(t)
{
    initDictionary(doc);
}

QString AbstractDictionary::getTranslation(const QString &word)
{
    for(auto it = dictionary.begin(); it != dictionary.end(); ++it)
    {
        DictNode curr = *it;
        QString translation = curr.contains(word);

        if(translation != "")
            return translation;
    }

    return word;
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

    pWord key = nullptr;
    pWord value = nullptr;

    QJsonObject fromObject = word.value("from").toObject();
    QJsonObject toObject = word.value("to").toObject();

    if(partOfSpeech == "noun")
    {
        key = new Noun(from , fromObject);
        value = new Noun(to, toObject);
    }
    else if(partOfSpeech == "verb")
    {
        key = new Verb(from, fromObject);
        value = new Verb(to, toObject);
    }
    else if(partOfSpeech == "adj")
        qDebug() << "adjective";
    else
        qDebug() << "undefined part of speech";

    if(key != nullptr && value != nullptr)
        dictionary.push_back(DictNode(key, value));
}
