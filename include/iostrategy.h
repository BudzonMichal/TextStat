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
        virtual err_t showMenu(vector<string> *text) = 0;
        virtual err_t updateMenu(key_e button) = 0;
        virtual err_t print(char* str)    = 0;
        virtual err_t print(int value);
        virtual err_t print(string str);
    protected:
        vector<string> *menuText;
        int             menuPos;
    private:
};

#endif // PRINTWIN_H
