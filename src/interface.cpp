#include <new>
#include <iostream>
#include "interface.h"
#include "iowindows.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

Interface* Interface::ins = 0;

Interface::Interface()
{
    cmd.type = CMD_NONE;
}

Interface::~Interface()
{
    //dtor
}

Command Interface::getCmd()
{
    return ins->cmd;
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

int Interface::routine(string arg)
{
    key_e  button;
    string file_path;
    int    current_menu;
    static bool no_init = false;
    ins->cmd.type       = CMD_NONE;

    if(ins == nullptr) return 1;

    if (!no_init){
        ins->menu.reset();
        ins->io->showMenu(ins->menu.getMenuText());
        no_init = true;
    }

    //ins->io->print("current file: " + arg + "\n");
    button = ins->io->checkKey(); // wait for pressed button
    ins->menu.updateMenu(button); // update menu properly
    ins->io->showMenu(ins->menu.getMenuText()); // show updated menu

    current_menu = ins->menu.getType();

    switch(current_menu){
        case FILE_MENU:
                file_path = ins->io->input(); // get data from user if necessary
                ins->menu.returnMain();
                ins->io->showMenu(ins->menu.getMenuText()); // show updated menu
                for(int i = 0 ; i < file_path.size() ; ++i) ins->cmd.arg.str[i] = file_path.at(i);
                ins->cmd.arg.str[file_path.size()] = 0;
                ins->cmd.type = CMD_OPEN;
                break;
        case STAT_MENU:
                ins->io->clearScreen();
                ins->io->print(arg);
                break;
    }

    return 0;
}

