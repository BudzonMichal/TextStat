/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#ifndef ABCANALYZER_H
#define ABCANALYZER_H

#include "analyzer.h"

using namespace std;

class ABCAnalyzer : public Analyzer
{
    public:
        ABCAnalyzer();
        ~ABCAnalyzer();
        err_t analyze(string filename);
        string getResult();
    protected:
    private:
};

#endif // ANALYZER_H
