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
protected:
    static QJsonDocument   getJsonDoc(const QString& address);

private: // Methods
    Dictionary      getDictionary(const QJsonDocument& doc);

private:
    Dictionary      dictionary;
};

#endif // ABSTRACTDICTIONARY_H
