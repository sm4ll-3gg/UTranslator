#include "noun.h"

#include <QDebug>

Noun::Noun(Language lang, const QJsonObject &word)
    :AbstractWord(lang, PartOfSpeech::NOUN)
{
    stem = word.value("stem").toString();
    gender = getGender( word.value("gender").toString() );
    singular = getDeclension( word.value("singular").toArray() );
    plural = getDeclension( word.value("plural").toArray() );
}

const Noun::Answer Noun::find(const QString &word) const
{
    for(int i = 0; i < singular.size(); ++i)
        if(word == singular[i])
            return Answer(true, Answer::Count::SINGULAR, i);

    for(int i = 0; i < plural.size(); ++i)
        if(word == plural[i])
            return Answer(true, Answer::Count::PLURAL, i);

    return Answer(false, Answer::Count::NONE, -1);
}

const QString &Noun::getStem() const
{
    return stem;
}

const QString &Noun::getFormOfWord(Noun::Answer::Count count, int index)
{
    if(count == Answer::Count::SINGULAR)
        return singular[index];
    else
        return plural[index];
}

Noun::Gender Noun::getGender(const QString &str)
{
    if(str == "middle")
        return Gender::MIDDLE;
    else if(str == "male")
        return Gender::MALE;
    else if(str == "female")
        return Gender::FEMALE;
    else qDebug() << "Undefined gender: " << str;

    return Gender::UNDEFINED;
}

Noun::Declensions Noun::getDeclension(const QJsonArray &arr)
{
    QVector<QString> v;

    for(auto it = arr.begin(); it != arr.end(); ++it)
        v.append( (*it).toString() );

    return v;
}
