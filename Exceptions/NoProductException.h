
#ifndef LAB9_10_NOPRODUCTEXCEPTION_H
#define LAB9_10_NOPRODUCTEXCEPTION_H


#include <exception>

class NoProductException: public std::exception {
public:

    NoProductException();

    const char* what() const noexcept;
};


#endif //LAB9_10_NOPRODUCTEXCEPTION_H
