#ifndef FILEREADER_H
#define FILEREADER_H

#include "enums.h"
#include <string>

using namespace std;

class FileReader
{
    public:
        FileReader();
        virtual ~FileReader();
        err_t  load(string filename);
        string getText();
    protected:
        string text;
    private:
};

#endif // FILEREADER_H
