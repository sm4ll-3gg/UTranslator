#ifndef NOUN_H
#define NOUN_H

#include "abstractword.h"

#include <QJsonObject>

class Noun final : private AbstractWord
{
public:
    explicit Noun(Language lang, const QJsonObject& word);
};

#endif // NOUN_H
