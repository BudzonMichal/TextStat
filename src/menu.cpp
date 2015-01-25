#include "menu.h"

Menu::Menu()
{
    menuText[MAIN_MENU].push_back("Set file");
    menuText[MAIN_MENU].push_back("Statistics");
    menuText[MAIN_MENU].push_back("Info");

    menuText[FILE_MENU].push_back("Pass filename:");

    reset();
}

Menu::~Menu()
{
    //dtor
}

err_t Menu::reset()
{
    menuPos = 0;
    menuType = 0;

    return ERR_OK;
}

err_t Menu::returnMain()
{
    menuPos = 1;
    menuType = MAIN_MENU;
}

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
    }

    return ERR_OK;
}

const string* Menu::getMenuText()
{
    currentMenu = "";

    if( menuText[menuType].size() == 0) return nullptr;

    currentMenu = " ________________________________ \n\n";

    switch(menuType){
        case MAIN_MENU:
                        for(int i = 0 ; i < menuText[menuType].size() ; ++i){
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
        case INFO_MENU:
                        break;
    }

    return &currentMenu;
}
