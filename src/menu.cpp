/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#include "menu.h"

/**@brief Constructor.
 */
Menu::Menu()
{
    menuText[MAIN_MENU].push_back("Set file");
    menuText[MAIN_MENU].push_back("Statistics");
    menuText[MAIN_MENU].push_back("Info");
    menuText[MAIN_MENU].push_back("Exit");

    menuText[FILE_MENU].push_back("Pass filename:");

    menuText[INFO_MENU].push_back("Program destined to generate text's statistics");

    returnMain();
}

/**@brief Destructor.
 */
Menu::~Menu()
{
}

/**@brief Function for resetting menu state and to get to main menu.
 *
 * @return      ERR_OK if success, error code otherwise.
 */
err_t Menu::returnMain()
{
    menuPos = 0;
    menuType = MAIN_MENU;

    return ERR_OK;
}

/**@brief Function for updating menu state.
 *
 * @param[in]   button  Pressed button.
 *
 * @return      ERR_OK on successful menu updating, error code otherwise.
 */
err_t Menu::updateMenu(key_e button)
{
    switch(button){
        case KEY_DOWN: if(menuPos < menuText[menuType].size()-1) ++menuPos;
            break;
        case KEY_UP:   if(menuPos > 0) --menuPos;
            break;
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            break;
        case KEY_ENTER: if(menuType == MAIN_MENU) menuType = menuPos + 1; // menuType==0 is main menu,
            break;
        case KEY_ESCAPE: menuType = MAIN_MENU;
            break;
        default:
            break;
    }

    return ERR_OK;
}

/**@brief Function for getting current menu text to print.
 *
 * @return      Menu text to be printed.
 */
const string* Menu::getMenuText()
{
    currentMenu = "";

    if( menuText[menuType].size() == 0) return &currentMenu;

    currentMenu = " ________________________________ \n\n";

    switch(menuType){
        case MAIN_MENU:
                        for(unsigned int i = 0 ; i < menuText[menuType].size() ; ++i){
                            currentMenu += "\t";
                            if((i == menuPos) && (menuType == MAIN_MENU)) currentMenu += "-> ";
                            else currentMenu += "   ";
                            currentMenu += menuText[menuType].at(i);
                            currentMenu += "\n";
                        }
                        currentMenu += " ________________________________ \n";
                        break;
        case FILE_MENU: currentMenu += " \tCHOOSE FILE TO ANALYSE \n";
                        currentMenu += " ________________________________ \n\n";
                        currentMenu += "\tfilename: ";

                        break;
        case STAT_MENU:
                        break;
        case INFO_MENU: currentMenu = menuText[INFO_MENU].at(0);
                        break;
    }

    return &currentMenu;
}
