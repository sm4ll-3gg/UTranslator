#include "rutoen.h"

RuToEn::RuToEn(QStringList&& input, QObject *parent)
    : QObject(parent),
      text(input)
{

}

QString&& RuToEn::translate()
{
}
