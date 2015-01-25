/* Copyright (c) 2015 Micha³ Budzoñ. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
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
#define EXIT_MENU 4

#define MAIN_SET  0
#define MAIN_STAT 1
#define MAIN_INFO 2
#define MAIN_EXIT 3

using namespace std;

class Menu
{
public:
    Menu();
    virtual ~Menu();
    err_t  updateMenu(key_e button);
    const string* getMenuText();
    err_t  reset();
    err_t  returnMain();
    int    getPos(){ return menuPos; } // number of cursor position in menu
    int    getType(){ return menuType; } // number of menu

protected:
    string                   currentMenu;
    std::vector<std::string> menuText[MENU_NUMBER];
    unsigned int             menuPos = 0;
    int                      menuType = 0;
private:
};

#endif // MENU_H
