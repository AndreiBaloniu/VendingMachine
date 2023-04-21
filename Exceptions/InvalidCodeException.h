

#ifndef LAB9_10_INVALIDCODEEXCEPTION_H
#define LAB9_10_INVALIDCODEEXCEPTION_H


#include <exception>

class InvalidCodeException: public std::exception{
public:
    InvalidCodeException();
    const char* what() const noexcept;

};


#endif //LAB9_10_INVALIDCODEEXCEPTION_H
