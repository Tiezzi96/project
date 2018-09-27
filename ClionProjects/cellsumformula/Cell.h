//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_CELL_H
#define CELLSUMFORMULA_CELL_H


#include "Subject.h"
#include "MyGrid.h"
#include <list>

class Cell : public Subject {
public:
    Cell(float v = 0) : value(v) {}

    virtual ~Cell() {}

    virtual void addObserver(Observer *o);

    virtual void removeObserver(Observer *o);

    virtual void notifyObservers();

    virtual void addGrid(MyGrid *grid);

    virtual void removeGrid(MyGrid *grid);

    virtual bool isObserver(Observer *o);


    float getValue() const {
        return value;
    }

    void setValue(float value) {
        Cell::value = value;
        notifyObservers();
    }

    unsigned long getObserversSize() {
        if (isObserver(nullptr) == true) {
            removeObserver(nullptr);
        }
        return observers.size();
    }

private:
    float value;
    std::list<MyGrid*> mygrid;
    std::list<Observer*>observers;

};


#endif //CELLSUMFORMULA_CELL_H
