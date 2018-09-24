//
// Created by bernardo on 02/10/16.
//

#ifndef CELLSUMFORMULA_MINFORMULA_H
#define CELLSUMFORMULA_MINFORMULA_H


#include <iostream>
#include "Observer.h"
#include "Cell.h"

class MinFormula: public Observer {
public:
    MinFormula(){}
    virtual ~MinFormula() {
        for(auto itr=cells.begin();itr!=cells.end();itr++){
            (*itr)->removeObserver(this);
        }
    }
    virtual void update(){
        calc();
    }
    virtual void addCell(Cell* c){
        cells.push_back(c);
        //    c->addObserver(this);
    }
    virtual void removeCell(Cell* c){
        cells.remove(c);
        //   c->removeObserver(this);
    }
    virtual void pop_back(){
        cells.pop_back();
    }


    float calc(){
        if(cells.size()==0){
            return 0;
        }
        auto itr=begin(cells);
        for(auto itr2=begin(cells);itr2!=end(cells); itr2++) {
            if ((*itr)->getValue() > (*itr2)->getValue())
                itr = itr2;
        }
        //std::cout << "il valore piu piccolo è: " << (*itr)->getValue() << std::endl;
        result=(*itr)->getValue();
        return result;
    }

private:
    float _value;
    std::list<Cell*>cells;
    Cell*subject;

};


#endif //CELLSUMFORMULA_MINFORMULA_H
