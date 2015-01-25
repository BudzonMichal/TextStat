#include "analyzerabc.h"
#include "filereader.h"
#include <iostream>
#include <sstream>

template < class T >
string to_string( T t )
{
    stringstream ss;
    ss << t;
    return ss.str();
}

ABCAnalyzer::ABCAnalyzer()
{
    //ctor
}

ABCAnalyzer::~ABCAnalyzer()
{
    //dtor
}

err_t ABCAnalyzer::analyze(string filename)
{
    FileReader fr;
    string     textfile;
    int        c_num = 0;
    int        b_num = 0;
    int        a_num = 0;
    int        line_num = 1;
    int        length;

    if( fr.load(filename) != ERR_OK){
        result = "Nie znaleziono pliku\n";
        return ERR_FAULT;
    }

    textfile = fr.getText();

    length = textfile.size();

    for(int i = 0 ; i < length ; ++i){
        switch(textfile[i]){
            case 'A':
            case 'a': a_num++;
                break;
            case 'B':
            case 'b': b_num++;
                break;
            case 'C':
            case 'c': c_num++;
                break;
            case '\n': line_num++;
                break;
        }
    }

    result =  "Analiza pliku " + filename + ":\n\n";
    result += "ilosc znakow: " + to_string(length);
    result += "\nilosc lini: " + to_string(line_num);
    result += "\nwystapienia A: " + to_string(a_num);
    result += "\nwystapienia B: " + to_string(b_num);
    result += "\nwystapienia C: " + to_string(c_num);

    return ERR_OK;
}

string ABCAnalyzer::getResult()
{
    return result;
}


