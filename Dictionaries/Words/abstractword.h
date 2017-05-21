#ifndef ABSTRACTWORD_H
#define ABSTRACTWORD_H

#include "languages.cpp"

#include <QObject>

class AbstractWord : public QObject
{
    Q_OBJECT

protected:
    using Language = Languages::Language;

    enum class PartOfSpeech{ NOUN = 0, VERB = 1, ADJ = 2 };

public:
    explicit AbstractWord(Language lang, PartOfSpeech pOs, QObject *parent = 0);

private:
    Language        language;
    PartOfSpeech    partOfSpeech;
};

#endif // ABSTRACTWORD_H
