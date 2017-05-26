#include "dictnode.h"

#include "Words/noun.h"
#include "Words/verb.h"

#include <QDebug>

DictNode::DictNode(pWord f, pWord t)
    :from(f), to(t) {}

const QString DictNode::contains(const QString &word)
{
    if( word.contains( from->getStem() ) )
    {
        using PartOfSpeech = Word::PartOfSpeech;
        PartOfSpeech partOfSpeech = from->getPartOfSpeech();

        if(partOfSpeech == PartOfSpeech::NOUN)
            return processNoun(word);
        else if(partOfSpeech == PartOfSpeech::VERB)
        {
            return processVerb(word);
        }
        else if(partOfSpeech == PartOfSpeech::ADJ)
            qDebug() << "Process adj";
    }

    return "";
}

const QString DictNode::processNoun(const QString &word)
{
    Noun* n_from = dynamic_cast<Noun*>(from);

    auto answer = n_from->find(word);

    if(answer.isFound)
    {
        Noun* n_to = dynamic_cast<Noun*>(to);
        return n_to->getFormOfWord(answer.count_, answer.case_);
    }

    return "";
}

const QString DictNode::processVerb(const QString &word)
{
    Verb* v_from = dynamic_cast<Verb*>(from);

    auto answer = v_from->find(word);

    if(answer.isFound)
    {
        Verb* v_to = dynamic_cast<Verb*>(to);
        return v_to->getFormOfWord(answer.time_, answer.case_);
    }

    return "";
}

