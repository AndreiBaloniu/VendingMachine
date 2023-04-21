

#ifndef LAB9_10_POSITIONEXCEPTIONS_H
#define LAB9_10_POSITIONEXCEPTIONS_H


#include <exception>

class PositionExceptions: public std::exception{
public:
    PositionExceptions();

    const char* what() const noexcept;
};


#endif //LAB9_10_POSITIONEXCEPTIONS_H
