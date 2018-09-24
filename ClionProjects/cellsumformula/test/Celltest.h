//
// Created by bernardo on 03/03/18.
//

#ifndef CELLSUMFORMULA_CELLTEST_H
#define CELLSUMFORMULA_CELLTEST_H

#include "../Cell.h"
#include "../SumFormula.h"
#include "gtest/gtest.h"
#include "../Observer.h"
#include "Formuletest.h"

class Celltest: public testing::Test {
protected:

    virtual void SetUp(){
        cell = new Cell;
        formulaSum = new SumFormula;
    }

    Cell* cell;
    SumFormula * formulaSum;


};


TEST_F(Celltest,CellConstructor){
    ASSERT_EQ(0, cell->getValue());
}

TEST_F(Celltest,AddObserver){
    cell->addObserver(formulaSum);
    formulaSum->addCell(cell);
    ASSERT_EQ(formulaSum->cellsSize(), 1);
    ASSERT_TRUE(cell->isObserver(formulaSum));
}

TEST_F(Celltest,RemoveObserver){
    unsigned long size = formulaSum->cellsSize();
    cell->addObserver(formulaSum);
    formulaSum->addCell(cell);
    cell->removeObserver(formulaSum);
    formulaSum->removeCell(cell);
    ASSERT_EQ(formulaSum->cellsSize(), size);
}

TEST_F(Celltest,Notify){
    cell->addObserver(formulaSum);
    formulaSum->addCell(cell);
    ASSERT_EQ(0,formulaSum->getResult());
    cell->setValue(10); //Il metodo setValue invoca Notify quindi si testa funzionamento del metodo Notify chiamando setValue
    ASSERT_EQ(10, formulaSum->getResult());
}

TEST_F(Celltest, DuplicateFormule){
    cell->addObserver(formulaSum);
    cell->addObserver(formulaSum);
    ASSERT_EQ(1,cell->getObserversSize());
}


#endif //CELLSUMFORMULA_CELLTEST_H
