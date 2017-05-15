#include "translator.h"

#include "Translators/rutoen.h"

#include <QStringList>

Translator::Translator(QObject *parent)
    : QObject(parent)
{}

QString&& Translator::translate(const QString &input, Language from, Language to)
{
    QStringList text = input.split(" ");

    if((from == Language::RU) &&
       (to == Language::EN))
        return RuToEn( std::move(text) ).translate();
}
