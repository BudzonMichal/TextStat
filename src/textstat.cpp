#include <new>
#include <iostream>
#include "textstat.h"
#include "interface.h"
#include "analyzerabc.h"

TextStat::TextStat()
{

}

TextStat::~TextStat()
{
    deallocate();
}

// Lazy Constructor

err_t TextStat::start()
{
    err_t  err = ERR_OK;
    string res = "no file";
    string filepath;

    if(allocate() != ERR_OK) return ERR_MEMORY;

    while(1){
      ui->routine(res);

      if(ui->getCmd().type == CMD_OPEN){
        an->analyze(ui->getCmd().arg.str);
        res = an->getResult();
      }
    }

    return err;
}

/******************************** PRIVATE FUNCTIONS ********************************/
err_t TextStat::deallocate()
{
    delete ui;
    ui = 0;
    delete an;
    an = 0;

    return ERR_OK;
}

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

err_t TextStat::setAnalyzer(Analyzer* analyzer)
{
    if(an != 0) delete an;
    an = analyzer;
}
