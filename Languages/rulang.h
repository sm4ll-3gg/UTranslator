#ifndef RU_RULANG_H
#define RU_RULANG_H

#include "abstractlanguage.h"

class RuLang final : private AbstractLanguage
{
    Q_OBJECT

public:
    static const RuLang& get()
    {
        static RuLang lang;
        return lang;
    }

private: // Methods
    explicit RuLang();
    RuLang(const RuLang&);
    RuLang& operator=(const RuLang) = delete;
};

#endif // RU_RULANG_H
