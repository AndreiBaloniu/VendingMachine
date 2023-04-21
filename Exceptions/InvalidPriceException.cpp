//
// Created by Baluta on 24.05.2022.
//
#include <cstring>
#include <string>
#include "InvalidPriceException.h"

InvalidPriceException::InvalidPriceException() = default;

const char *InvalidPriceException::what() const noexcept {
    std::string msg ="Pretul nu este valid";
    char* copy_msg = new char[msg.length() +1];
    strcpy_s(copy_msg, msg.length()+1,msg.c_str());

    const char* res = const_cast<char*>(copy_msg);

    return res;

}

InvalidPriceException::InvalidPriceException(int pret) {
    this->pret = pret;
}
