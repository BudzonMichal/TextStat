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
            case IO_LEFT:  return KEY_LEFT; // key_e
            case IO_RIGHT: return KEY_RIGHT; // key_e
            case IO_UP:    return KEY_UP; // key_e
            case IO_DOWN:  return KEY_DOWN; // key_e
        }
    }
    return (key_e)button;
}

err_t IOWindows::print(char* cs)
{

   return ERR_OK;
}

err_t IOWindows::showMenu(vector<string> *text)
{
    if (text == 0) return ERR_NULL;
    menuText = text;
    menuPos = 1;
    updateMenu((key_e)0);
}

err_t IOWindows::updateMenu(key_e button)
{
    switch(button){
        case 0: break;
        case KEY_UP:   if(menuPos > 1) --(menuPos); break;
        case KEY_DOWN: if(menuPos < menuText->size() - 2) ++(menuPos); break;
        default: return ERR_FAULT;
    }

    system("cls");

    cout << " " << menuText->at(0);

    for(int i = 1 ; i < menuText->size() - 1; ++i){
        if(i == menuPos) cout << "*" << menuText->at(i);
        else cout << " " << menuText->at(i);
    }

    cout << menuText->at(menuText->size() - 1);
}
