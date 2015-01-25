#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "enums.h"

#define MENU_NUMBER 4

#define MAIN_MENU 0
#define FILE_MENU 1
#define STAT_MENU 2
#define INFO_MENU 3

using namespace std;

class Menu
{
public:
    Menu();
    virtual ~Menu();
    err_t updateMenu(key_e button);
    const string* getMenuText();
    err_t reset();
    err_t returnMain();
    int   getPos(){ return menuPos; } // number of cursor position in menu
    int   getType(){ return menuType; } // number of menu

protected:
    string                   currentMenu;
    std::vector<std::string> menuText[MENU_NUMBER];
    int                      menuPos = 0;
    int                      menuType = 0;
private:
};

#endif // MENU_H
