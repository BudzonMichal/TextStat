/* Copyright (c) 2015 Micha³ Budzoñ. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */

#include "ioaccess.h"
#include <stdio.h>


/**@brief Constructor.
 */
IOAccess::IOAccess()
{
}


/**@brief Destructor.
 */
IOAccess::~IOAccess()
{
}

/**@brief Function for printing the integer value.
 *
 * @param[in]  Ineger to be printed.
 *
 * @return     ERR_OK if success, error code otherwise.
 */
err_t IOAccess::print(int value)
{
    char table[16];
    sprintf(table, "%d", value);
    print(table);

    return ERR_OK;
}

/**@brief Function for printing the std::string.
 *
 * @param[in]  String to be printed.
 *
 * @return     ERR_OK if success, error code otherwise.
 */
err_t IOAccess::print(string str)
{
    const char* cs = str.c_str();
    print(cs);

    return ERR_OK;
}

err_t IOAccess::showMenu(const string* txt)
{
    clearScreen();
    //printf((*txt).c_str());
    print((*txt).c_str());
}
