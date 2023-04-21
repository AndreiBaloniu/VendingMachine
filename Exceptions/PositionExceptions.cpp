

#include "PositionExceptions.h"
#include <cstring>
#include <string>

PositionExceptions::PositionExceptions() = default;

const char *PositionExceptions::what() const noexcept {
    std::string msg ="Nu exista un produs cu aceasta pozitie";
    char* copy_msg = new char[msg.length() +1];
    strcpy_s(copy_msg, msg.length()+1,msg.c_str());

    const char* res = const_cast<char*>(copy_msg);

    return res;
}
