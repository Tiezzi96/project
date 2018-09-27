//
// Created by bernardo on 02/10/16.
//

#include "MinFormula.h"

MinFormula::~MinFormula() {
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        (*itr)->removeObserver(this);
    }
}

void MinFormula::update() {
    calc();
}

void MinFormula::addCell(Cell *c) {
    cells.push_back(c);
}

void MinFormula::removeCell(Cell *c) {
    cells.remove(c);
}

void MinFormula::pop_back() {
    cells.pop_back();
}


float MinFormula::calc() {
    if (cells.size() == 0) {
        return 0;
    }
    auto itr = begin(cells);
    for (auto itr2 = begin(cells); itr2 != end(cells); itr2++) {
        if ((*itr)->getValue() > (*itr2)->getValue())
            itr = itr2;
    }
    result = (*itr)->getValue();
    return result;
}

