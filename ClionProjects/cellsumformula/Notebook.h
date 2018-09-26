//
// Created by bernardo on 15/10/17.
//

#ifndef CELLSUMFORMULA_NOTEBOOK_H
#define CELLSUMFORMULA_NOTEBOOK_H


#include "wx/wx.h"
#include "wx/grid.h"
#include "wx/notebook.h"
#include "Cell.h"
#include "MaxFormula.h"
#include "MinFormula.h"
#include "MeanFormula.h"
#include "SumFormula.h"
#include "MyGrid.h"
#include <list>
#include <iostream>
#include "ListException.h"
class Notebook: public wxFrame
{
public:

    Notebook(const wxString& title);

    void OnQuit(wxCommandEvent & event);
    void OnChangeValue(wxCommandEvent & event);
    void newCell(wxCommandEvent & event)throw(NumberCellsOutOfRangeException);
    float newcell();
    void deleteCell(wxCommandEvent &event) throw(NumberCellsUnderflowException);
    void sumFormula(wxCommandEvent &event);
    void maxFormula(wxCommandEvent &event);
    void minFormula(wxCommandEvent &event);
    void meanFormula(wxCommandEvent &event);
    void cellscontrol(wxCommandEvent &event);
    void change_value(wxCommandEvent &event);
    bool isFull();
    bool isEmpty();



private:
    std::list<MyGrid*>grid;
    std::list<Cell*>cells;
    std::list<float>Float;
    MaxFormula Max;
    MinFormula Min;
    MeanFormula Mean;
    SumFormula Sum;
    wxTextCtrl *ctrl;
    wxTextCtrl *ctrl1;
    wxTextCtrl *ctrl2;



};



#endif //CELLSUMFORMULA_NOTEBOOK_H
