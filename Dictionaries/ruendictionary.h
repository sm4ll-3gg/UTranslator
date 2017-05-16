#ifndef RUENDICTIONARY_H
#define RUENDICTIONARY_H

#include "abstractdictionary.h"

class RuEnDictionary final : private AbstractDictionary
{
    Q_OBJECT

public:
    static RuEnDictionary& get()
    {
        static RuEnDictionary d;
        return d;
    }

private: // Methods
    RuEnDictionary();
    RuEnDictionary(const RuEnDictionary&);
    RuEnDictionary& operator=(const RuEnDictionary&) = delete;
    ~RuEnDictionary();



};

#endif // RUENDICTIONARY_H
