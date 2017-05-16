#ifndef ABSTRACTDICTIONARY_H
#define ABSTRACTDICTIONARY_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QJsonDocument>

class AbstractDictionary : public QObject
{
    Q_OBJECT

protected:
    using Dictionary = QMap<QString, QString>;

public:
    explicit AbstractDictionary(const QJsonDocument& dictionaryDocument,
                                QObject *parent = 0);
private: // Methods
    Dictionary  constructDictionaryFromJson(const QJsonDocument& doc);

private:
    Dictionary  dictionary;
};

#endif // ABSTRACTDICTIONARY_H
