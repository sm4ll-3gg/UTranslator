#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "languages.cpp"

#include <QObject>
#include <QString>
#include <QMap>

class Translator : public QObject
{
    Q_OBJECT

    using Language = Languages::Language;

public:
    explicit Translator(QObject *parent = 0);

public slots:
    QString translate(const QString& input, Language from, Language to);
};

#endif // TRANSLATOR_H
