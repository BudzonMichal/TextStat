#include "iostrategy.h"

#include <stdio.h>

IOStrategy::IOStrategy()
{
    //ctor
}

IOStrategy::~IOStrategy()
{
    //dtor
}

err_t IOStrategy::print(int value)
{
    char table[16];
    sprintf(table, "%d", value);
    print(table);
}

err_t IOStrategy::print(string str)
{
    const char* cs = str.c_str();
    print(cs);
}

err_t IOStrategy::showMenu(const string* txt)
{
    clearScreen();
    //printf((*txt).c_str());
    print((*txt).c_str());
}
