#include "ruendictionary.h"

RuEnDictionary::RuEnDictionary()
    :AbstractDictionary(QJsonDocument::fromJson("../UTranslator/Dictionaries/RuToEn.json"))
{

}

RuEnDictionary::~RuEnDictionary()
{

}
