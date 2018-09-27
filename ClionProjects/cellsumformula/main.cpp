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

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit() {
    Notebook *notebook = new Notebook(wxT("Notebook"));
    notebook->Show(true);

    return true;
}


