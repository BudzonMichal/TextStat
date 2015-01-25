/* Copyright (c) 2015 Micha³ Budzoñ. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#ifndef ANALYZER_H
#define ANALYZER_H

#include <string>
#include "enums.h"

using namespace std;

class Analyzer
{
    public:
        Analyzer();
        virtual ~Analyzer();
        virtual err_t analyze(string filename) = 0;
        virtual string getResult() = 0;
    protected:
        string result;
    private:
};

#endif // ANALYZER_H
