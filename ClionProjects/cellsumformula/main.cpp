#include <iostream>
#include "Cell.h"
#include "SumFormula.h"
#include "MaxFormula.h"
#include "MinFormula.h"
#include "MeanFormula.h"
#include <wx/wx.h>

using namespace std;

int main() {

    Cell c1(2.1);
    Cell c2(2.0);
    Cell c3(2.887);
    Cell c4(2.12);
    MaxFormula m;
    m.addCell(&c1);
    m.addCell(&c2);
    m.addCell(&c3);
    m.addCell(&c4);
    m.calc();

}