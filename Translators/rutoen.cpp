#include "rutoen.h"

#include <QDebug>
#include <QJsonDocument>

RuToEn::RuToEn(QStringList&& input, QObject *parent)
    : QObject(parent),
      text(input)
{
    RuEnDictionary::get();
}

QString&& RuToEn::translate()
{
}
