#ifndef PRINTWIN_H
#define PRINTWIN_H

#include "iostrategy.h"
#include "enums.h"

#define IO_ARROW 224
#define IO_ENTER 13
#define IO_UP    72
#define IO_LEFT  75
#define IO_RIGHT 77
#define IO_DOWN  80

class IOWindows : public IOStrategy
{
    public:
        IOWindows();
        virtual ~IOWindows();

        key_e checkKey();
        err_t print(const char* str);
        err_t clearScreen();
    protected:
    private:
};

#endif // PRINTWIN_H
