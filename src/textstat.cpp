/* Copyright (c) 2015 Michał Budzoń. All Rights Reserved.
 *
 * Licensees are granted free, non-transferable use of the information. NO
 * WARRANTY of ANY KIND is provided. This heading must NOT be removed from
 * the file.
 */
#include <new>
#include <iostream>
#include "textstat.h"
#include "interface.h"
#include "analyzerabc.h"

/**@brief Constructor.
 */
TextStat::TextStat()
{
}

/**@brief Destructor.
 */
TextStat::~TextStat()
{
    deallocate();
}

/**@brief Function for starting text statistics program.
 *
 * @return      ERR_OK on successful exit from program, error code otherwise.
 */
err_t TextStat::start()
{
    err_t  err = ERR_OK;
    string res = "no file";
    string filepath;

    if(allocate() != ERR_OK) return ERR_MEMORY;

    while(1){
      ui->routine(res); // wait for user action (press button & update the screen)

      if(ui->getCmd().type == CMD_ANALYZE){ // if result of user action was to analyze a file...
        an->analyze(ui->getCmd().arg.str);
        res = an->getResult();
      }
      if(ui->getCmd().type == CMD_EXIT){ // if result of user action was to exit
        break;
      }
    }

    return err;
}

/**@brief Function for deallocating memory.
 *
 * @return      ERR_OK when successfully deallocated, error code otherwise.
 */
err_t TextStat::deallocate()
{
    delete ui;
    ui = 0;
    delete an;
    an = 0;

    return ERR_OK;
}

/**@brief Function for allocating memory.
 *
 * @return      ERR_OK when successfully allocated, error code otherwise.
 */
err_t TextStat::allocate()
{
    err_t err = ERR_OK;

    err = Interface::getInstance(ui);
    setAnalyzer(new (std::nothrow)ABCAnalyzer()); // setStrategy

    if(!an || (err != ERR_OK)){
        deallocate();
        return ERR_MEMORY;
    }

    return ERR_OK;
}

/**@brief Function for setting the analyzer instance.
 *
 * @return      ERR_OK if analyzer established, error code otherwise.
 */
err_t TextStat::setAnalyzer(Analyzer* analyzer)
{
    if(an != 0) delete an;
    an = analyzer;

    return ERR_OK;
}
