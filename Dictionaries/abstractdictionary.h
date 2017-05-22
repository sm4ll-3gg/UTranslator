#ifndef ABSTRACTDICTIONARY_H
#define ABSTRACTDICTIONARY_H

//#include "Words/abstractword.h"
#include "dictnode.h"

#include <memory>
#include <QObject>
#include <QList>
#include <QString>
#include <QJsonDocument>

class AbstractDictionary : public QObject
{
    Q_OBJECT

protected:
    using Language = Languages::Language;

    using pWord = AbstractWord*;
    using Dictionary = QList<DictNode>;

public:
    explicit AbstractDictionary(Language from, Language to,
                                const QJsonDocument& doc,
                                QObject *parent = 0);

    QString                 getTranslation(const QString& word);

protected:
    static QJsonDocument    getJsonDoc(const QString& address);

private: // Methods
    void                    initDictionary(const QJsonDocument& doc);

    void                    processJsonObject(const QJsonObject& word);



    void                    appendNoun(const QJsonObject& word);

private:
    Language        from;
    Language        to;

    Dictionary      dictionary;
};

#endif // ABSTRACTDICTIONARY_H
