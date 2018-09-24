#include <iostream>
#include <list>
#include "Cell.h"
#include "SumFormula.h"
#include "MaxFormula.h"
#include "MinFormula.h"
#include "MeanFormula.h"
#include <wx/wx.h>
#include "main.h"
#include "Notebook.h"

using namespace std;

/*
int main() {
    Cell c1(2.1);
    Cell c2(2.0);
    Cell c3(2.887);
    Cell c4(2.12);
    SumFormula m;
    m.addCell(&c1);
    m.addCell(&c2);
    m.addCell(&c3);
    m.addCell(&c4);
    m.calc();
    m.removeCell(&c3);
    m.calc();
    std::list<Cell>cells;
    cells.push_back(c1);
    cells.push_back(c2);
    cells.push_back(c3);
    cells.push_back(c4);
    cells.push_back(c1);
    cells.push_back(c1);
    int r= (int) cells.size();
    int d = rand() % r;
    std::cout<<"il size di cells è "<< r<<"," << d<< std::endl;
    cells.pop_back();
    r=(int)cells.size();
    std::cout<<"il size di cells è "<< r<<"," << d<< std::endl;


}
*/


IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    Notebook * notebook = new Notebook(wxT("Notebook"));
    notebook->Show(true);

    return true;
}


