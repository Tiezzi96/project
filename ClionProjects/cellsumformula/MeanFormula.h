//
// Created by bernardo on 02/10/16.
//

#ifndef CELLSUMFORMULA_MEANFORMULA_H
#define CELLSUMFORMULA_MEANFORMULA_H


#include <iostream>
#include "Observer.h"
#include "Cell.h"

class MeanFormula : public Observer {
public:
    MeanFormula() {}

    virtual ~MeanFormula();

    virtual void update();

    virtual void addCell(Cell *c);

    virtual void removeCell(Cell *c);

    virtual void pop_back();


    float calc() override;


private:
    std::list<Cell *> cells;

};


#endif //CELLSUMFORMULA_MEANFORMULA_H
