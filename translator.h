#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <QObject>
#include <QString>
#include <QMap>

namespace Language {
enum Language{EN = 0, RU = 1};

using Pair = std::pair<QString, Language>;

static const QMap<QString, Language> languages{
            Pair("Русский", RU),
            Pair("Английский", EN)};
}

class Translator : public QObject
{
    Q_OBJECT

    using Language = Language::Language;

public:
    explicit Translator(QObject *parent = 0);

public slots:
    QString translate(const QString& input, Language from, Language to);
};

#endif // TRANSLATOR_H
