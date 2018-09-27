//
// Created by bernardo on 28/09/16.
//

#include "SumFormula.h"


SumFormula::~SumFormula() {
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        (*itr)->removeObserver(this);
    }
}

void SumFormula::addCell(Cell *c) {
    cells.push_back(c);
};

void SumFormula::removeCell(Cell *c) {
    cells.remove(c);
}

void SumFormula::pop_back() {
    cells.pop_back();
}

void SumFormula::update() {
    calc();
}

unsigned long SumFormula::cellsSize() {
    return cells.size();
};

std::list<Cell *> SumFormula::getcell() {
    return cells;
};


float SumFormula::calc() {
    float r = 0;
    for (auto itr = begin(cells); itr != end(cells); itr++) {
        r += (*itr)->getValue();
    }
    result = r;
    return result;
}
