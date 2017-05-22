#include "ruendictionary.h"

RuEnDictionary::RuEnDictionary()
    :AbstractDictionary(Language::RU, Language::EN,
                        getJsonDoc("../UTranslator/Dictionaries/RuEn.json"))
{}

RuEnDictionary::~RuEnDictionary()
{

}
