/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
 #include "filereader.h"
#include <iostream>
#include <fstream>
#include <streambuf>

/**@brief Constructor.
 */
FileReader::FileReader()
{
}

/**@brief Destructor.
 */
FileReader::~FileReader()
{
}

err_t FileReader::load(string filename)
{
    ofstream myfile;
    myfile.open (filename.c_str(), ios::in);

    if(!myfile.is_open()) return ERR_FAULT; // check if file exist
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
