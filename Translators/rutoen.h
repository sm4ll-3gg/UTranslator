#ifndef RUTOEN_H
#define RUTOEN_H

#include "Languages/enlang.h"
#include "Languages/rulang.h"

#include <QObject>
#include <QStringList>

class RuToEn : public QObject
{
    Q_OBJECT
public:
    explicit RuToEn(QStringList&& text, QObject *parent = 0);

    QString&& translate();

private:
    QStringList text;
};

#endif // RUTOEN_H
