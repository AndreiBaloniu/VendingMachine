//
// Created by Baluta on 17.05.2022.
//

#include <string>
#include <cstring>
#include "ValutaExceptions.h"

ValutaExceptions::ValutaExceptions() = default;

const char *ValutaExceptions::what() const noexcept {
    std::string msg ="Nu exista o valuta cu aceasta pozitie";
    char* copy_msg = new char[msg.length() +1];
    strcpy_s(copy_msg, msg.length()+1,msg.c_str());

    const char* res = const_cast<char*>(copy_msg);

    return res;
}
