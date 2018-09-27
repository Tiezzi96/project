//
// Created by bernardo on 20/09/18.
//

#ifndef CELLSUMFORMULA_FORMULETEST_H
#define CELLSUMFORMULA_FORMULETEST_H

#include "gtest/gtest.h"
#include "../SumFormula.h"
#include "../MeanFormula.h"
#include "../MinFormula.h"
#include "../MaxFormula.h"
#include "../Cell.h"

class Formuletest : public testing::Test {
public:
    virtual void SetUp() {

        cells = new Cell[3];

        cells[0] = Cell(10.4);
        cells[1] = Cell(4.5);
        cells[2] = Cell(6.7);


        formulaSum = new SumFormula;
        formulaMax = new MaxFormula;
        formulaMin = new MinFormula;
        formulaMean = new MeanFormula;

        cells[0].addObserver(formulaSum);
        cells[0].addObserver(formulaMax);
        cells[0].addObserver(formulaMin);

        formulaSum->addCell(&cells[0]);
        formulaMin->addCell(&cells[0]);
        formulaMax->addCell(&cells[0]);

        cells[1].addObserver(formulaMean);
        cells[1].addObserver(formulaMax);
        cells[1].addObserver(formulaMin);

        formulaMean->addCell(&cells[1]);
        formulaMin->addCell(&cells[1]);
        formulaMax->addCell(&cells[1]);

        cells[2].addObserver(formulaSum);
        cells[2].addObserver(formulaMean);
        cells[2].addObserver(formulaMax);

        formulaMean->addCell(&cells[2]);
        formulaSum->addCell(&cells[2]);
        formulaMax->addCell(&cells[2]);
    }

    Cell getCell(int number) {
        return cells[number];
    }

protected:
    Cell *cells;
    SumFormula *formulaSum;
    MaxFormula *formulaMax;
    MeanFormula *formulaMean;
    MinFormula *formulaMin;


};


TEST_F(Formuletest, CalcoloMassimo) {
    formulaMax->update();
    ASSERT_FLOAT_EQ(formulaMax->getResult(), 10.4);
}


TEST_F(Formuletest, CalcoloMinimo) {
    formulaMin->update();
    ASSERT_FLOAT_EQ(formulaMin->getResult(), 4.5);
}


TEST_F(Formuletest, CalcoloMedia) {
    formulaMean->update();
    float r = formulaMean->getResult();
    ASSERT_FLOAT_EQ(r, ((4.5 + 6.7) / 2));
}


TEST_F(Formuletest, CalcoloSomma) {
    formulaSum->update();
    float r = formulaSum->getResult();
    ASSERT_FLOAT_EQ(r, 17.1);
}


TEST_F(Formuletest, DeleteFormula) {
    delete formulaMin;
    ASSERT_FLOAT_EQ(2, getCell(1).getObserversSize());

}





#endif //CELLSUMFORMULA_FORMULETEST_H
