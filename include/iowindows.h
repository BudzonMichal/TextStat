/* Copyright (c) 2015 Micha³ Budzoñ. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#ifndef PRINTWIN_H
#define PRINTWIN_H

#include "ioaccess.h"
#include "enums.h"

#define IO_ARROW 224
#define IO_ENTER 13
#define IO_UP    72
#define IO_LEFT  75
#define IO_RIGHT 77
#define IO_DOWN  80

class IOWindows : public IOAccess
{
    public:
        IOWindows();
        virtual ~IOWindows();

        key_e   checkKey();
        err_t   print(const char* str);
        err_t   clearScreen();
        string  input();
    protected:
    private:
        void    moveCursor(int x);
};

#endif // PRINTWIN_H
