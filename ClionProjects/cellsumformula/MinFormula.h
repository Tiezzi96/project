//
// Created by bernardo on 02/10/16.
//

#ifndef CELLSUMFORMULA_MINFORMULA_H
#define CELLSUMFORMULA_MINFORMULA_H


#include <iostream>
#include "Observer.h"
#include "Cell.h"

class MinFormula : public Observer {
public:
    MinFormula() {}

    virtual ~MinFormula();

    virtual void update();

    virtual void addCell(Cell *c);

    virtual void removeCell(Cell *c);

    virtual void pop_back();


    float calc() override;

private:
    std::list<Cell *> cells;

};


#endif //CELLSUMFORMULA_MINFORMULA_H
