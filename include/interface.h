#ifndef INTERFACE_H
#define INTERFACE_H

#include "enums.h"
#include "menu.h"
#include <string>
#include <vector>

class Interface;
class IOStrategy;

class Interface
{
    public:
        static err_t getInstance(Interface* instance);
        virtual ~Interface();

        int   loop();
        err_t item(int number);

    protected:
    private:
        Interface();
        err_t setStrategy(); //unknown type of passed argument?

        static Interface *ins;
        IOStrategy       *io = 0;
        Menu             menu;
};

#endif // INTERFACE_H
