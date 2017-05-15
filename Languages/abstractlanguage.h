#ifndef ABSTRACTLANGUAGE_H
#define ABSTRACTLANGUAGE_H

#include <QObject>
#include <QSet>
#include <QString>

class AbstractLanguage : public QObject
{
    Q_OBJECT

protected:
    // Множество поддерживаемых слов
    using Words = QSet<QString>;
    using WordList = std::initializer_list<QString>;

public:
    AbstractLanguage() = delete;
    explicit AbstractLanguage(const WordList& wordList, QObject *parent = 0);

protected:
    Words   words;
};

#endif // ABSTRACTLANGUAGE_H
