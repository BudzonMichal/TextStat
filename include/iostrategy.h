#ifndef IOSTRATEGY_H
#define IOSTRATEGY_H
#include <string>
#include "enums.h"

using namespace std;

class IOStrategy
{
    public:
        IOStrategy();
        virtual ~IOStrategy();

        virtual int   checkKey()    = 0;
        virtual err_t menu()             = 0;
        virtual err_t print(char* str)  = 0;
        virtual err_t print(int value);
        virtual err_t print(string str);
    protected:
    private:
};

#endif // PRINTWIN_H
