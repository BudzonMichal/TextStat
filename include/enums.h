#ifndef ENUMS_H
#define ENUMS_H

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
    CMD_OPEN = 1
} ;

struct Command
{
    int type;
    union{
        char str[64];
        int  integer[16];
    } arg;
};


#endif // ENUMS_H_INCLUDED
