#include <new>
#include <iostream>
#include "interface.h"
#include "iowindows.h"
#include <stdlib.h>

using namespace std;

Interface* Interface::ins = 0;

Interface::Interface()
{

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

    return ERR_OK;
}

int Interface::loop()
{
    key_e button;

    if(ins == nullptr) return ERR_NULL;

    ins->menu.reset();
    ins->io->showMenu(ins->menu.getMenu());

    while(1){
        button = ins->io->checkKey();
        ins->menu.updateMenu(button);
        if(ins->menu.getNum() == MAIN_MENU) ins->io->showMenu(ins->menu.getMenu());
        else ins->io->clearScreen();
    }

    return 0;
}

err_t Interface::item(int number)
{
    ins->io->print(number);

    return ERR_OK;
}
