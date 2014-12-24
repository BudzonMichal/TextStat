#include <new>
#include <iostream>
#include "interface.h"
#include "iowindows.h"
#include <stdlib.h>

using namespace std;

Interface* Interface::ins = 0;

Interface::Interface()
{
    menuText.push_back("\n***** MENU ******\n");
    menuText.push_back("1. One \n");
    menuText.push_back("2. Two \n");
    menuText.push_back("3. Three \n");
    menuText.push_back("***************\n\n");
}

Interface::~Interface()
{
    //dtor
}

err_t Interface::getInstance(Interface* instance)
{
    instance = (Interface*)0;

    if(!ins){
        ins = new (std::nothrow)Interface();
        if(ins == 0) return ERR_MEMORY;
        if(instance->setStrategy() != ERR_OK) return ERR_INTERNAL;
    }

    instance = ins;

    return ERR_OK;
}

err_t Interface::setStrategy()
{
    delete ins->io;
    ins->io = new (std::nothrow)IOWindows(); // you can change strategy here

    if(!ins->io) return ERR_MEMORY;
    cout << "strategy set\n";
    return ERR_OK;
}

int Interface::loop()
{
    key_e button;

    while(1){
        button = ins->io->checkKey();
        updateMenu(button);
    }

    return 0;
}

err_t Interface::startMenu()
{
    ins->io->showMenu(&(ins->menuText));

    return ERR_OK;
}

err_t Interface::updateMenu(key_e button)
{
    ins->io->updateMenu(button);

    return ERR_OK;
}

err_t Interface::item(int number)
{
    ins->io->print(number);

    return ERR_OK;
}
