#include "rutoen.h"

#include <QDebug>
#include <QJsonDocument>

RuToEn::RuToEn(QStringList&& input, QObject *parent)
    : QObject(parent),
      text(input)
{}

QString RuToEn::translate()
{
    QString translation("");

    for(QString curr : text)
    {
        translation += RuEnDictionary::get().getTranslation(curr) + " ";
    }

    return translation;
}
