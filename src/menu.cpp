#include "menu.h"

Menu::Menu()
{
    menuText[MAIN_MENU].push_back("Set file");
    menuText[MAIN_MENU].push_back("Statistics");
    menuText[MAIN_MENU].push_back("Info");

    reset();
}

Menu::~Menu()
{
    //dtor
}

err_t Menu::reset()
{
    menuPos = 0;
    menuNum = 0;
}

err_t Menu::updateMenu(key_e button)
{
    switch(button){
        case KEY_DOWN: if(menuPos < menuText[menuNum].size()-1) ++menuPos;
            break;
        case KEY_UP:   if(menuPos > 0) --menuPos;
            break;
        case KEY_LEFT:
            break;
        case KEY_RIGHT:
            break;
        case KEY_ENTER: if(menuNum == MAIN_MENU) menuNum = menuPos + 1;
            break;
        case KEY_ESCAPE: menuNum = MAIN_MENU;
            break;
    }
}

const string* Menu::getMenu()
{
    currentMenu = "";

    if( menuText[menuNum].size() == 0) return nullptr;

    currentMenu = " ________________________________ \n\n";

    for(int i = 0 ; i < menuText[menuNum].size() ; ++i){
        currentMenu += "\t";
        if(i == menuPos) currentMenu += "-> ";
        else currentMenu += "   ";
        currentMenu += menuText[menuNum].at(i);
        currentMenu += "\n";
    }

    currentMenu += " ________________________________ \n";

    return &currentMenu;
}
