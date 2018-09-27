//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_SUMFORMULA_H
#define CELLSUMFORMULA_SUMFORMULA_H


#include "Cell.h"
#include <list>
#include <iostream>

class SumFormula : public Observer {
public:
    SumFormula() {}

    ~SumFormula();

    virtual void addCell(Cell *c);

    virtual void removeCell(Cell *c);

    virtual void pop_back();

    virtual void update();

    virtual unsigned long cellsSize();

    virtual std::list<Cell *> getcell();


    float calc() override;


private:
    std::list<Cell *> cells;


};


#endif //CELLSUMFORMULA_SUMFORMULA_H
