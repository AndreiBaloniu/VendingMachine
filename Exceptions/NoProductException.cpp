
#include <cstring>
#include <string>
#include "NoProductException.h"

NoProductException::NoProductException() = default;

const char *NoProductException::what() const noexcept {
    std::string msg ="Nu exista un produs cu acest cod";
    char* copy_msg = new char[msg.length() +1];
    strcpy_s(copy_msg, msg.length()+1,msg.c_str());

    const char* res = const_cast<char*>(copy_msg);

    return res;
}
