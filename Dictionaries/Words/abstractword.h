#ifndef ABSTRACTWORD_H
#define ABSTRACTWORD_H

#include "languages.h"

#include <QObject>

namespace Word {
enum class PartOfSpeech{ NOUN = 0, VERB = 1, ADJ = 2 };
}

class AbstractWord : public QObject
{
    Q_OBJECT

protected:
    using Language = Languages::Language;
    using PartOfSpeech = Word::PartOfSpeech;

public:
    struct Answer
    {
        bool    answer;
        QString word;

        Answer(bool b, QString s)
            :answer(b), word(s) {}
    };

    explicit AbstractWord(Language lang, PartOfSpeech pOs, QObject *parent = 0);

    virtual const QString&  getStem() const = 0;

    PartOfSpeech            getPartOfSpeech() { return partOfSpeech; }

private:
    Language        language;
    PartOfSpeech    partOfSpeech;
};

#endif // ABSTRACTWORD_H
