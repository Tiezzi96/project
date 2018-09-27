//
// Created by bernardo on 02/10/16.
//

#include "MeanFormula.h"

MeanFormula::~MeanFormula() {
    for (auto itr = cells.begin(); itr != cells.end(); itr++) {
        (*itr)->removeObserver(this);
    }
}

void MeanFormula::update() {
    calc();
}

void MeanFormula::addCell(Cell *c) {
    cells.push_back(c);

}

void MeanFormula::removeCell(Cell *c) {
    cells.remove(c);

}

void MeanFormula::pop_back() {
    cells.pop_back();
}


float MeanFormula::calc() {
    int count = 0;
    float r = 0;
    for (auto itr = begin(cells); itr != end(cells); itr++) {
        count++;
        r += (*itr)->getValue();
    }
    r /= count;
    result = r;
    return r;
}






