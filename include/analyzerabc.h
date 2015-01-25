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
