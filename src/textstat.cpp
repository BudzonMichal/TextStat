#include <new>
#include "textstat.h"
#include "interface.h"
#include "storage.h"
#include "analyzer.h"

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
    int button;
    err_t err = ERR_OK;

    if(allocate() != ERR_OK) return ERR_MEMORY;

    if(ui->menu()) return ERR_UI;

    while(1){
        button = ui->waitForPress();
        //ui->item(button);

        if(button) break;
    }

    return err;
}



/******************************** PRIVATE FUNCTIONS ********************************/
err_t TextStat::deallocate()
{
    delete ui;
    ui = 0;
    delete st;
    st = 0;
    delete an;
    an = 0;

    return ERR_OK;
}

err_t TextStat::allocate()
{
    err_t err = ERR_OK;

    err = Interface::getInstance(ui); // setStrategy
    st = new (std::nothrow)Storage();
    an = new (std::nothrow)Analyzer();

    if(!st || !an || err){
        deallocate();
        return ERR_MEMORY;
    }

    return ERR_OK;
}
