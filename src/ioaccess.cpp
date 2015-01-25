#include "ioaccess.h"

#include <stdio.h>

IOAccess::IOAccess()
{
    //ctor
}

IOAccess::~IOAccess()
{
    //dtor
}

err_t IOAccess::print(int value)
{
    char table[16];
    sprintf(table, "%d", value);
    print(table);

    return ERR_OK;
}

err_t IOAccess::print(string str)
{
    const char* cs = str.c_str();
    print(cs);

    return ERR_OK;
}

err_t IOAccess::showMenu(const string* txt)
{
    clearScreen();
    if(txt == nullptr) return ERR_NULL;
    print((*txt).c_str());

    return ERR_OK;
}
