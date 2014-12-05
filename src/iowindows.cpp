#include "iowindows.h"
//#include <stdio.h>
#include <iostream>

IOWindows::IOWindows()
{
    //ctor
}

IOWindows::~IOWindows()
{
    //dtor
}

int IOWindows::checkKey()
{
    cout << "press any key:";
    return 0;
}

err_t IOWindows::print(char* cs)
{
   //printf(cs);

   return ERR_OK;
}

err_t IOWindows::menu()
{
    cout << "menu: interface\n";
}
