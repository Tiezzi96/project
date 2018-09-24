//
// Created by bernardo on 02/10/16.
//

#ifndef CELLSUMFORMULA_MEANFORMULA_H
#define CELLSUMFORMULA_MEANFORMULA_H


#include <iostream>
#include "Observer.h"
#include "Cell.h"

class MeanFormula: public Observer {
public:
    MeanFormula(){}
    virtual ~MeanFormula() {
        for(auto itr=cells.begin();itr!=cells.end();itr++) {
            (*itr)->removeObserver(this);
        }
    }
    virtual void update(){
        calc();
    }
    virtual void addCell(Cell* c){
        cells.push_back(c);
        //   c->addObserver(this);

    }
    virtual void removeCell(Cell* c){
        cells.remove(c);
        //   c->removeObserver(this);

    }
    virtual void pop_back(){
        cells.pop_back();
    }


    float calc(){
        int count=0;
        float r=0;
        for(auto itr=begin(cells); itr!=end(cells); itr++){
            count++;
            r+=(*itr)->getValue();
        }
        r /=count;
        //std::cout << "la media dei valori è: " << r << std::endl;
        result=r;
        return r;
    }





private:
    float _value;
    std::list<Cell*>cells;
    Cell* subject;

};


#endif //CELLSUMFORMULA_MEANFORMULA_H
