#ifndef INTERFACE_H
#define INTERFACE_H

#include "enums.h"

class Interface;
class IOStrategy;

class Interface
{
    public:
        static err_t getInstance(Interface* instance);
        virtual ~Interface();

        int waitForPress();
        err_t menu();
        err_t item(int number);

    protected:
    private:
        Interface();
        err_t setStrategy(void); //unknown type of passed argument?

        static Interface *ins;
        IOStrategy       *io = 0;
};

#endif // INTERFACE_H
