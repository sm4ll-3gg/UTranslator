#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QString>

namespace Language {
    enum Language{EN = 0, RU = 1};
}

class Translator : public QObject
{
    Q_OBJECT

    using Language = Language::Language;

public:
    explicit Translator(QObject *parent = 0);

public slots:
    QString &&translate(const QString& input, Language from, Language to);
};

#endif // TRANSLATOR_H
