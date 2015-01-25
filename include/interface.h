#ifndef INTERFACE_H
#define INTERFACE_H

#include "enums.h"
#include "menu.h"
#include <string>
#include <vector>

class Interface;
class IOAccess;

class Interface
{
    public:
        static err_t getInstance(Interface* instance);
        virtual ~Interface();

        int     routine(string arg);
       // err_t   item(int number);
        Command getCmd();

    protected:
    private:
        Interface();
        err_t setStrategy(); //unknown type of passed argument?

        static Interface *ins;
        IOAccess         *io = 0;
        Menu             menu;
        Command          cmd;
};

#endif // INTERFACE_H
