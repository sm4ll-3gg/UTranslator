#include "verb.h"

#include <QJsonArray>

Verb::Verb(Language lang, const QJsonObject &obj)
    :AbstractWord(lang, PartOfSpeech::VERB)
{
    stem = obj.value("stem").toString();

    infinitive = obj.value("infinitive").toString();
    present = getDeclension( obj.value("present").toArray() );
    past = getDeclension( obj.value("past").toArray() );
}

const QString &Verb::getStem() const
{
    return stem;
}

const Verb::Answer Verb::find(const QString &word) const
{
    if(infinitive == word)
        return Answer(true, Answer::Time::INFINITIVE, 0);

    for(int i = 0; i < present.size(); ++i)
        if(word == present[i])
            return Answer(true, Answer::Time::PRESENT, i);

    for(int i = 0; i < past.size(); ++i)
        if(word == past[i])
            return Answer(true, Answer::Time::PAST, i);

    return Answer(false, Answer::Time::NONE, -1);
}

const QString &Verb::getFormOfWord(Verb::Answer::Time time, int index)
{
    if(time == Answer::Time::INFINITIVE)
        return infinitive;
    else if(time == Answer::Time::PRESENT)
        return present[index];
    else
        return past[index];
}

Verb::Declensions Verb::getDeclension(const QJsonArray &arr)
{
    QVector<QString> v;

    for(auto it = arr.begin(); it != arr.end(); ++it)
        v.append( (*it).toString() );

    return v;
}
