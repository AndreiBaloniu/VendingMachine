//
// Created by Baluta on 24.05.2022.
//

#ifndef LAB9_10_INVALIDPRICEEXCEPTION_H
#define LAB9_10_INVALIDPRICEEXCEPTION_H


#include <exception>

class InvalidPriceException: public std::exception{
private:
    int pret;
public:
    InvalidPriceException();
    explicit InvalidPriceException(int pret);

    const char* what() const noexcept override;
};


#endif //LAB9_10_INVALIDPRICEEXCEPTION_H
