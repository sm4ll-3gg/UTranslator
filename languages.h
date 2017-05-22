#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <QMap>

namespace Languages {
enum Language{EN = 0, RU = 1};

using Pair = std::pair<QString, Language>;

static const QMap<QString, Language> languages{
            Pair("Русский", RU),
            Pair("Английский", EN)};
}

#endif // LANGUAGES_H
