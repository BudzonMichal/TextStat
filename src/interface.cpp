#include <new>
#include <iostream>
#include "interface.h"
#include "iowindows.h"

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
    cout << "strategy set\n";
    return ERR_OK;
}

int Interface::waitForPress()
{
    cout << "ad";
    return ins->io->checkKey();
}

err_t Interface::menu()
{
    cout << "menu: interface\n";
    cout << ins->io;
    //io->menu();

    return ERR_OK;
}

err_t Interface::item(int number)
{
    ins->io->print(number);

    return ERR_OK;
}
