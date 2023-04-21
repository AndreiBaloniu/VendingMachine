//
// Created by Baluta on 17.05.2022.
//

#ifndef LAB9_10_VALUTAEXCEPTIONS_H
#define LAB9_10_VALUTAEXCEPTIONS_H


#include <exception>

class ValutaExceptions: public std::exception{
public:
    ValutaExceptions();

    const char* what() const noexcept;
};


#endif //LAB9_10_VALUTAEXCEPTIONS_H
