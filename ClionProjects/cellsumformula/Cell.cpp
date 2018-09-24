//
// Created by bernardo on 28/09/16.
//

#include "Cell.h"

void Cell::addObserver(Observer *o) {
    if(!isObserver(o))
        observers.push_back(o);
}
void Cell::removeObserver(Observer *o) {
    observers.remove(o);
}
void Cell::notifyObservers() {
    for(auto itr=observers.begin();itr!=observers.end();itr++){
        (*itr)->update();
    }

}

void Cell::addGrid(MyGrid *grid) {
    mygrid.push_back(grid);
}
void Cell::removeGrid(MyGrid *grid) {
    mygrid.remove(grid);
}

bool Cell::isObserver(Observer *o) {
    for (auto itr=observers.begin();itr!=observers.end();itr++) {
        if((*itr)==o)
            return true;
    }
    return false;
}