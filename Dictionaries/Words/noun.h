#ifndef NOUN_H
#define NOUN_H

#include "abstractword.h"

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>
#include <QString>

class Noun final : public AbstractWord
{
    using Declensions = QVector<QString>;

    enum class Gender { UNDEFINED = 0, MIDDLE = 1, MALE = 2, FEMALE = 3};

public:
    struct Answer
    {
        enum class Count{NONE           = -1,
                         SINGULAR       = 0,
                         PLURAL         = 1};

        bool    isFound;
        Count   count_;
        int     case_;

        Answer(bool b, Count co, int ca)
            :isFound(b), count_(co), case_(ca) {}
    };

    explicit Noun(Language lang, const QJsonObject& word);

    const Answer find(const QString& word) const;

    const QString&  getStem() const override;
    const QString&  getFormOfWord(Answer::Count count, int index);

private: // Methods
    Gender      getGender(const QString& str);
    Declensions getDeclension(const QJsonArray& arr);

private:
    Gender      gender;

    QString     stem;

    Declensions singular;
    Declensions plural;
};

#endif // NOUN_H
