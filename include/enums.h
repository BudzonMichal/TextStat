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
    KEY_LEFT = 200,
    KEY_RIGHT,
    KEY_UP,
    KEY_DOWN,
} key_e;


#endif // ENUMS_H_INCLUDED
