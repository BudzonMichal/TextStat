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

/**@brief Function for waiting and reacting for the user action.
 *
 * @param[in]  Some string argument.
 *
 * @return     ERR_OK if success, error code otherwise.
 */
err_t Interface::routine(string arg)
{
    key_e  button;
    string file_path;
    int    current_menu;
    static bool no_init = false;  //

    ins->cmd.type       = CMD_NONE;  // default command

    if(ins == nullptr) return ERR_MEMORY; // return if no instance created

    if (!no_init){ // check if function was called first time...
        ins->menu.returnMain();
        ins->io->clearScreen();
        ins->io->print(ins->menu.getMenuText());
        no_init = true;
    }

    button = ins->io->checkKey(); // wait for pressed button
    ins->menu.updateMenu(button); // update menu properly
    ins->io->clearScreen();       // clear screen and...
    ins->io->print(ins->menu.getMenuText()); // ...show updated menu

    current_menu = ins->menu.getType();  // get to know what is currently showed

    switch(current_menu){
        case EXIT_MENU: // if ENTER pressed when exit selected
                if(ins->menu.getPos() == MAIN_EXIT) ins->cmd.type = CMD_EXIT;
                break;
        case FILE_MENU: // if ENTER pressed when "set file" selected in menu
                file_path = ins->io->input(); // get data from user if necessary
                ins->menu.returnMain();
                ins->io->clearScreen();
                ins->io->print(ins->menu.getMenuText()); // show updated menu
                for(unsigned int i = 0 ; i < file_path.size() ; ++i) ins->cmd.arg.str[i] = file_path.at(i);
                ins->cmd.arg.str[file_path.size()] = 0;
                ins->cmd.type = CMD_ANALYZE;
                break;
        case STAT_MENU: // if ENTER pressed when "statistics" selected in menu
                ins->io->clearScreen();
                ins->io->print(arg);
                break;
    }

    return ERR_OK;
}

