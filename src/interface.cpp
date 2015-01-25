/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#include <new>
#include <iostream>
#include "interface.h"
#include "iowindows.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

Interface* Interface::ins = 0;

/**@brief Constructor.
 */
Interface::Interface()
{
    cmd.type = CMD_NONE;
}

/**@brief Destructor.
 */
Interface::~Interface()
{
}

/**@brief Function for getting the command requested by the interface.
 *
 * @return Type of command.
 */
Command Interface::getCmd()
{
    return ins->cmd;
}

/**@brief Function for getting the class' instance. It's singleton design pattern.
 *
 * @param[out]   instance  The instance of the class.
 *
 * @return      NRF_SUCCESS on successful creation of the instance, error code otherwise.
 */
err_t Interface::getInstance(Interface* instance)
{
    instance = (Interface*)0;

    if(!ins){
        ins = new (std::nothrow)Interface();
        if(ins == 0) return ERR_MEMORY;
        if(instance->setImplementation() != ERR_OK) return ERR_INTERNAL;
    }

    instance = ins;

    return ERR_OK;
}

/**@brief Function for setting
 *
 * @return      NRF_SUCCESS on successful creation of the instance, error code otherwise.
 */
err_t Interface::setImplementation()
{
    delete ins->io;
#ifdef SYSTEM_WINDOWS
    ins->io = new (std::nothrow)IOWindows();
#else
    ins->io = new (std::nothrow)IOLinux();
#endif

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
        ins->menu.returnMain();
        ins->io->showMenu(ins->menu.getMenuText());
        no_init = true;
    }

    //ins->io->print("current file: " + arg + "\n");
    button = ins->io->checkKey(); // wait for pressed button
    ins->menu.updateMenu(button); // update menu properly
    ins->io->showMenu(ins->menu.getMenuText()); // show updated menu

    current_menu = ins->menu.getType();

    switch(current_menu){
        case EXIT_MENU:
                if(ins->menu.getPos() == MAIN_EXIT) ins->cmd.type = CMD_EXIT;
                break;
        case FILE_MENU:
                file_path = ins->io->input(); // get data from user if necessary
                ins->menu.returnMain();
                ins->io->showMenu(ins->menu.getMenuText()); // show updated menu
                for(unsigned int i = 0 ; i < file_path.size() ; ++i) ins->cmd.arg.str[i] = file_path.at(i);
                ins->cmd.arg.str[file_path.size()] = 0;
                ins->cmd.type = CMD_ANALYZE;
                break;
        case STAT_MENU:
                ins->io->clearScreen();
                ins->io->print(arg);
                break;
    }

    return 0;
}

