//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_SUMFORMULA_H
#define CELLSUMFORMULA_SUMFORMULA_H


#include "Cell.h"
#include <list>
#include <iostream>

class SumFormula: public Observer {
public:
    SumFormula(){}
    ~SumFormula(){
        for(auto itr=cells.begin();itr!=cells.end();itr++) {
            (*itr)->removeObserver(this);
        }
    }
    virtual void addCell(Cell * c){
        cells.push_back(c);
    };
    virtual void removeCell(Cell * c){
        cells.remove(c);
    }
    virtual void pop_back(){
        cells.pop_back();
    }

    virtual void update() {
        calc();
    }
    virtual unsigned long cellsSize(){
        return cells.size();
    };

    virtual std::list <Cell*> getcell(){
        return cells;
    };






    float calc(){
        float r=0;
        for(auto itr=begin(cells); itr!=end(cells); itr++){
            r += (*itr)->getValue();
        }
        //std::cout << "il risultato è: " << r << std::endl;
        result = r;
        return result;
    }





private:
    std::list<Cell*>cells;
    Cell* subject;
    float _value;

};


#endif //CELLSUMFORMULA_SUMFORMULA_H
