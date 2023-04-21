
#include <cstring>
#include <string>
#include "InvalidCodeException.h"

InvalidCodeException::InvalidCodeException() = default;

const char *InvalidCodeException::what() const noexcept {
    std::string msg ="Codul trebuie sa fie un numar pozitiv";
    char* copy_msg = new char[msg.length() +1];
    strcpy_s(copy_msg, msg.length()+1,msg.c_str());

    const char* res = const_cast<char*>(copy_msg);

    return res;
}
