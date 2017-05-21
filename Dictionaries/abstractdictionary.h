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
    explicit AbstractDictionary(const QJsonDocument& doc,
                                QObject *parent = 0);

    QString                 getTranslation(const QString& word);

protected:
    static QJsonDocument    getJsonDoc(const QString& address);

private: // Methods
    void                    initDictionary(const QJsonDocument& doc);
    void                    processJsonObject(const QJsonObject& word);

private:
    Dictionary      dictionary;
};

#endif // ABSTRACTDICTIONARY_H
