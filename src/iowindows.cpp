#include "iowindows.h"
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

#define INPUT_BUFF_SIZE 56

IOWindows::IOWindows()
{
    //ctor
}

IOWindows::~IOWindows()
{
    //dtor
}

void IOWindows::moveCursor(int x)
{
    COORD newPos;
    CONSOLE_SCREEN_BUFFER_INFO SBInfo;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &SBInfo);
    newPos = SBInfo.dwCursorPosition;
    newPos.X += x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), newPos);
}

key_e IOWindows::checkKey()
{
    int button = getch();

    if (button == IO_ARROW){
        button = getch();

        switch(button){
            case IO_LEFT:  return KEY_LEFT;  // key_e
            case IO_RIGHT: return KEY_RIGHT; // key_e
            case IO_UP:    return KEY_UP;    // key_e
            case IO_DOWN:  return KEY_DOWN;  // key_e
        }
    }
    return (key_e)button;
}

err_t IOWindows::print(const char* cs)
{
   printf(cs);
   return ERR_OK;
}

err_t IOWindows::clearScreen()
{
   system("cls");
   return ERR_OK;
}

string IOWindows::input()
{
   char   input[INPUT_BUFF_SIZE+1];
   int    key;
   int    i = 0;

   while(1)
   {
        key = getch();
        if(key == KEY_ESCAPE) return ""; // discard
        if(key == KEY_ENTER) return string(input);  // accept
        if(key == KEY_BACKSPACE && i > 0){
            moveCursor(-1);
            printf(" ");
            moveCursor(-1);
            input[i] = 0;
            --i;
        }
        if(((key == 90) || (key >= 45 && key <= 122)) && i < INPUT_BUFF_SIZE){  // if char passed
            input[i] = key;
            input[i+1] = 0;
            printf("%c", key);
            ++i;
        }
   }

   return string(input);
}
