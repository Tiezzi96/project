//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_CELL_H
#define CELLSUMFORMULA_CELL_H


#include "Subject.h"
#include <list>

class Cell: public Subject {
public:
    Cell(float v=0):value(v){}
    virtual ~Cell() { }
    virtual void addObserver(Observer * o);
    virtual void removeObserver(Observer * o);
    virtual void notifyObservers();


    float getValue() const {
        return value;
    }

    void setValue(float value) {
        Cell::value = value;
        notifyObservers();
    }

private:
    float value;
    std::list<Observer*>observers;

};


#endif //CELLSUMFORMULA_CELL_H
