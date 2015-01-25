#ifndef INTERFACE_H
#define INTERFACE_H
/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
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

        err_t routine(string arg);
        Command getCmd();

    protected:
    private:
        Interface();
        err_t setImplementation();

        static Interface *ins;
        IOAccess         *io = 0;
        Menu             menu;
        Command          cmd;
};

#endif // INTERFACE_H
