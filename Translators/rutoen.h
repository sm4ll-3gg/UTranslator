#ifndef RUTOEN_H
#define RUTOEN_H

#include "Dictionaries/ruendictionary.h"

#include <QObject>
#include <QMap>
#include <QString>
#include <QStringList>

class RuToEn : public QObject
{
    Q_OBJECT

public: // Methods
    explicit RuToEn(QStringList&& text, QObject *parent = 0);

    QString&& translate();

//private:
    //static Dictionary  getDictionary();

private:
    QStringList text;
};

#endif // RUTOEN_H
