#ifndef IOSTRATEGY_H
#define IOSTRATEGY_H

#include <string>
#include "enums.h"
#include <vector>

using namespace std;

class IOAccess
{
    public:
        IOAccess();
        virtual ~IOAccess();

        virtual key_e   checkKey()                = 0;
        virtual err_t   print(const char* str)    = 0;
        virtual err_t   clearScreen()             = 0;
        virtual string  input()                   = 0;
        err_t   showMenu(const string* txt);
        err_t   print(int value);
        err_t   print(string str);
    protected:
        virtual void    moveCursor(int x)         = 0;
    private:
};

#endif // PRINTWIN_H
