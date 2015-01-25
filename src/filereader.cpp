#include "filereader.h"
#include <iostream>
#include <fstream>
#include <streambuf>

FileReader::FileReader()
{
    //ctor
}

FileReader::~FileReader()
{
    //dtor
}

err_t FileReader::load(string filename)
{
    ofstream myfile;
    myfile.open (filename.c_str(), ios::in);

    if(!myfile.is_open()) return ERR_FAULT;
    myfile.close();

    text.clear();

    ifstream stream(filename.c_str());

    stream.seekg(0, ios::end);
    text.reserve(stream.tellg());
    stream.seekg(0, ios::beg);

    text.assign((istreambuf_iterator<char>(stream)), istreambuf_iterator<char>());

    return ERR_OK;
}

string FileReader::getText()
{
    return text;
}
