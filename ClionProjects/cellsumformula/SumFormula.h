//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_SUMFORMULA_H
#define CELLSUMFORMULA_SUMFORMULA_H


#include "Cell.h"
#include <list>
#include <iostream>

class SumFormula {
public:
    SumFormula(){}
    virtual void addCell(Cell * c){
        cells.push_back(c);
    };
    virtual void removeCell(Cell * c){
        cells.remove(c);
    }
    virtual void update(){
        _value=subject->getValue();
    }

    void calc(){
        float result=0;
        for(auto itr=begin(cells); itr!=end(cells); itr++){
            result += (*itr)->getValue();
        }
        std::cout << "il risultato è: " << result << std::endl;
    }





private:
    std::list<Cell*>cells;
    Cell* subject;
    float _value;

};


#endif //CELLSUMFORMULA_SUMFORMULA_H
