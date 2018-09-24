//
// Created by bernardo on 23/09/18.
//

#ifndef CELLSUMFORMULA_LISTEXCEPTION_H
#define CELLSUMFORMULA_LISTEXCEPTION_H

#include <stdexcept>

class NumberCellsOutOfRangeException : public std::out_of_range {
public:
    NumberCellsOutOfRangeException(const std::string &c=""):out_of_range(c.c_str()){
        std::cout<<c.c_str()<<std::endl;
    }

};

class NumberCellsUnderflowException : public std::out_of_range {
public:
    NumberCellsUnderflowException(const std::string &u=""):out_of_range(u.c_str()){
        std::cout<<u.c_str()<<std::endl;
    }

};


#endif //CELLSUMFORMULA_LISTEXCEPTION_H
