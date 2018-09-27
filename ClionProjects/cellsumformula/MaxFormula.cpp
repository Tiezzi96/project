//
// Created by bernardo on 02/10/16.
//

#include "MaxFormula.h"

MaxFormula::~MaxFormula() {
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        (*itr)->removeObserver(this);
    }
}

void MaxFormula::addCell(Cell *c) {
    cells.push_back(c);

}

void MaxFormula::removeCell(Cell *c) {
    cells.remove(c);

}

void MaxFormula::pop_back() {
    cells.pop_back();
}


void MaxFormula::update() {
    calc();
}

float MaxFormula::calc() {
    if (cells.size() == 0) {
        return 0;
    }
    auto itr = begin(cells);
    for (auto itr2 = begin(cells); itr2 != end(cells); itr2++) {
        if ((*itr)->getValue() < (*itr2)->getValue())
            itr = itr2;
    }
    result = (*itr)->getValue();
    return result;
}

