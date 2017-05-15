#include "abstractlanguage.h"

AbstractLanguage::AbstractLanguage(const AbstractLanguage::WordList &wordList,
                                   QObject *parent)
    : QObject(parent),
      words(wordList)
{

}
