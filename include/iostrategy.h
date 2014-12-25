#ifndef IOSTRATEGY_H
#define IOSTRATEGY_H

#include <string>
#include "enums.h"
#include <vector>

using namespace std;

class IOStrategy
{
    public:
        IOStrategy();
        virtual ~IOStrategy();

        virtual key_e checkKey()          = 0;
        virtual err_t print(const char* str)    = 0;
        virtual err_t clearScreen()       = 0;

        virtual err_t print(int value);
        virtual err_t print(string str);
        virtual err_t showMenu(const string* txt);
    private:
};

#endif // PRINTWIN_H
