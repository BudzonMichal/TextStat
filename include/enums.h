/* Copyright (c) 2015 Micha³ Budzoñ. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#ifndef ENUMS_H
#define ENUMS_H

#define SYSTEM_WINDOWS

enum err_t{
    ERR_OK,
    ERR_FAULT,
    ERR_MEMORY,
    ERR_UNKNOWN,
    ERR_UI,
    ERR_INTERNAL,
    ERR_NULL
};

typedef enum {
    KEY_BACKSPACE = 8,
    KEY_ENTER = 13,
    KEY_ESCAPE = 27,
    KEY_LEFT = 200,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
} key_e;

enum cmd_t{
    CMD_NONE = 0,
    CMD_ANALYZE = 1,
    CMD_EXIT = 2
};

struct Command
{
    int type;
    union{
        char str[64];
        int  integer[16];
    } arg;
};


#endif // ENUMS_H_INCLUDED
