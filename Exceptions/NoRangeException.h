//
// Created by Baluta on 25.05.2022.
//

#ifndef LAB9_10_NORANGEEXCEPTION_H
#define LAB9_10_NORANGEEXCEPTION_H

#include <exception>

class NoRangeException: public std::exception {
public:

    NoRangeException();

    const char* what() const noexcept;
};

#endif //LAB9_10_NORANGEEXCEPTION_H
