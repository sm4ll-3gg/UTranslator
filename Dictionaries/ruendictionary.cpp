#include "ruendictionary.h"

RuEnDictionary::RuEnDictionary()
    :AbstractDictionary(getJsonDoc("../UTranslator/Dictionaries/RuEn.json"))
{}

RuEnDictionary::~RuEnDictionary()
{

}
