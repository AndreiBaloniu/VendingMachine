#include <cstring>
#include <iostream>
#include "Money.h"


Money::Money() {
    this->value = 0;
    this->type = new char[10];
}
Money::Money(const char* param_type, double param_value) {
    this->value = param_value;
    this->type = new char[strlen(param_type) + 1];
    strcpy_s(this->type, strlen(param_type) + 1, param_type);
}
Money::Money(const Money& v) {
    this->value = v.value;
    this->type = new char[strlen(v.type) + 1];
    strcpy_s(this->type, strlen(v.type) + 1, v.type);
}

void Money::set_value(double param_value) {
    this->value = param_value;
}

void Money::set_type(const char* param_tpye) {
    this->type = new char[strlen(param_tpye) + 1];
    strcpy_s(this->type, strlen(param_tpye) + 1, param_tpye);
}

double Money::get_value() {
    return this->value;
}

const char* Money::get_type() {
    return this->type;
}

Money& Money::operator=(const Money& v) {
    if (this != &v)
    {
        if (this->type != nullptr) delete[] this->type;
        this->type = new char[strlen(v.type) + 1];
        strcpy_s(this->type, strlen(v.type) + 1, v.type);
        this->value = v.value;
    }
    return *this;
}

bool Money::operator==(const Money& v) {
    return (this->value == v.value) && (strcmp(this->type, v.type) == 0);

}

Money::~Money() {
    if (this->type != nullptr) delete[] this->type;
}
void Money::to_string() {
    std::cout << "Tip: " << this->get_type() << ", Valoare: " << this->get_value() << std::endl;
}

