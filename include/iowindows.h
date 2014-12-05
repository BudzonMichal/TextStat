#ifndef PRINTWIN_H
#define PRINTWIN_H

#include "iostrategy.h"

class IOWindows : public IOStrategy
{
    public:
        IOWindows();
        virtual ~IOWindows();

        int checkKey();
        err_t menu();
        err_t print(char* str);
    protected:
    private:
};

#endif // PRINTWIN_H
