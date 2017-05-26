#ifndef VERB_H
#define VERB_H

#include "abstractword.h"

#include <QString>
#include <QVector>
#include <QJsonObject>

class Verb : public AbstractWord
{
    using Declensions = QVector<QString>;

public:
    struct Answer
    {
         enum class Time{NONE           = -1,
                         INFINITIVE     = 0,
                         PRESENT        = 1,
                         PAST           = 2};

        bool    isFound;
        Time    time_;
        int     case_;

        Answer(bool b, Time t, int c)
            :isFound(b), time_(t), case_(c) {}
    };

    explicit Verb(Language lang, const QJsonObject& obj);

    const QString&  getStem() const override;

    const Answer    find(const QString& word) const;
    const QString&  getFormOfWord(Answer::Time time, int index);

private: // Methods
    Declensions getDeclension(const QJsonArray &arr);

private:
    QString     stem;

    QString     infinitive;
    Declensions present;
    Declensions past;
};

#endif // VERB_H
