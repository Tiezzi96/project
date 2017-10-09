//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_SUBJECT_H
#define CELLSUMFORMULA_SUBJECT_H


#include "Observer.h"

class Subject {
public:
    virtual void addObserver(Observer * o)=0;
    virtual void removeObserver(Observer * o)=0;
    virtual void notifyObservers()=0;


};


#endif //CELLSUMFORMULA_SUBJECT_H
