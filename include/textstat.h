#ifndef TEXTSTAT_H
#define TEXTSTAT_H

#include "enums.h"

class Interface;
class Storage;
class Analyzer;
class TextStat;

class TextStat
{
public:
    TextStat() ;
    virtual ~TextStat();

    err_t start();

protected:
private:
    err_t allocate();
    err_t deallocate();

    Interface *ui = 0;
    Storage   *st = 0;
    Analyzer  *an = 0;
};

#endif // TEXTSTAT_H
