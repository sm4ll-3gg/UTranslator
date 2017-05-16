#include "abstractdictionary.h"

#include <QDebug>
#include <QFile>

AbstractDictionary::AbstractDictionary(const QJsonDocument &doc, QObject *parent)
    : QObject(parent)
{
    getDictionary(doc);
}

QJsonDocument AbstractDictionary::getJsonDoc(const QString &address)
{
    QFile file(address);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    return QJsonDocument::fromJson(file.readAll());
}

AbstractDictionary::Dictionary AbstractDictionary::getDictionary(const QJsonDocument &doc)
{
    qDebug() << doc.isEmpty();
    return Dictionary();
}
