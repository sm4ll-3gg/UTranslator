#ifndef EN_USLANG_H
#define EN_USLANG_H

#include "abstractlanguage.h"

class EnLang final : private AbstractLanguage
{
    Q_OBJECT

public:
    static const EnLang& get()
    {
        static EnLang lang;
        return lang;
    }

private: // Methods
    explicit EnLang();
    EnLang(const EnLang&);
    EnLang& operator=(const EnLang) = delete;
};

#endif // EN_USLANG_H
