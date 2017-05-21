#include "abstractword.h"

AbstractWord::AbstractWord(Language lang, PartOfSpeech pOs, QObject *parent)
    :QObject(parent),
     language(lang),
     partOfSpeech(pOs)
{}
