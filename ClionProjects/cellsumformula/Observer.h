//
// Created by bernardo on 28/09/16.
//

#ifndef CELLSUMFORMULA_OBSERVER_H
#define CELLSUMFORMULA_OBSERVER_H



class Observer {
public:
    virtual void update() =0;

    float getResult(){
        return result;
    }

protected:
    float result= 0;
};


#endif //CELLSUMFORMULA_OBSERVER_H
