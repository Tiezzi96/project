//
// Created by bernardo on 02/10/16.
//

#ifndef CELLSUMFORMULA_MAXFORMULA_H
#define CELLSUMFORMULA_MAXFORMULA_H


#include <iostream>
#include "Observer.h"
#include "Cell.h"

class MaxFormula : public Observer {
public:
    MaxFormula() {}

    virtual ~MaxFormula();

    virtual void addCell(Cell *c);

    virtual void removeCell(Cell *c);

    virtual void pop_back();


    virtual void update();

    float calc() override;

private:
    std::list<Cell *> cells;

};





#endif //CELLSUMFORMULA_MAXFORMULA_H
