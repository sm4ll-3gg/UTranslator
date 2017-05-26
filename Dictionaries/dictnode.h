#ifndef DICTNODE_H
#define DICTNODE_H

#include "Words/abstractword.h"

class DictNode
{
    using pWord = AbstractWord*;

public:   
    explicit DictNode(pWord f, pWord t);

    const QString contains(const QString& word);

private: // Methods
    const QString   processNoun(const QString& word);
    const QString   processVerb(const QString& word);

private:
    pWord   from;
    pWord   to;
};

#endif // DICTNODE_H
