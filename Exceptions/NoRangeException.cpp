
#include <cstring>
#include <string>
#include "NoRangeException.h"

NoRangeException::NoRangeException() = default;

const char *NoRangeException::what() const noexcept {
    std::string msg ="Valoare trebuie cuprinsa intre 0 si 500";
    char* copy_msg = new char[msg.length() +1];
    strcpy_s(copy_msg, msg.length()+1,msg.c_str());

    const char* res = const_cast<char*>(copy_msg);

    return res;
}