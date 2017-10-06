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
    virtual ~MeanFormula() { }
    virtual void update()override{
        _value=subject->getValue();
    }
    virtual void addCell(Cell* c){
        cells.push_back(c);
        //   c->addObserver(this);

    }
    virtual void removeCell(Cell* c){
        cells.remove(c);
        //   c->removeObserver(this);

    }

    void calc(){
        int count=0;
        float result=0;
        for(auto itr=begin(cells); itr!=end(cells); itr++){
            count++;
            result+=(*itr)->getValue();
        }
        result /=count;
        std::cout << "la media dei valori è: " << result << std::endl;
    }





private:
    float _value;
    std::list<Cell*>cells;
    Cell* subject;

};


#endif //CELLSUMFORMULA_MEANFORMULA_H
