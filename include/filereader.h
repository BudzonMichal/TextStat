/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
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
