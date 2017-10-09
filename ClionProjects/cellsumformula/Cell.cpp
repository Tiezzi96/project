//
// Created by bernardo on 28/09/16.
//

#include "Cell.h"

void Cell::addObserver(Observer *o) {
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