#include "iowindows.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <stdlib.h>

IOWindows::IOWindows()
{
    //ctor
}

IOWindows::~IOWindows()
{
    //dtor
}

key_e IOWindows::checkKey()
{
    int button = getch();

    if (button == IO_ARROW){
        button = getch();

        switch(button){
            case IO_LEFT:  return KEY_LEFT;  // key_e
            case IO_RIGHT: return KEY_RIGHT; // key_e
            case IO_UP:    return KEY_UP;    // key_e
            case IO_DOWN:  return KEY_DOWN;  // key_e
        }
    }
    return (key_e)button;
}

err_t IOWindows::print(const char* cs)
{
   printf(cs);
   return ERR_OK;
}

err_t IOWindows::clearScreen()
{
   system("cls");
   return ERR_OK;
}

