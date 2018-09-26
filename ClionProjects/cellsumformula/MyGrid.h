//
// Created by bernardo on 16/10/17.
//

#ifndef CELLSUMFORMULA_MYGRID_H
#define CELLSUMFORMULA_MYGRID_H


#include <wx/notebook.h>
#include <wx/grid.h>


class MyGrid: public wxGrid{
public:
    MyGrid(wxNotebook *parent);
    void change_value();
};



#endif //CELLSUMFORMULA_MYGRID_H
