

#include "Product.h"
#include <cstring>
Product::Product(){
    code=0;
    price=0;
    name= nullptr;
}
Product::Product(int param_code, char* param_name, int param_price){
    this->code=param_code;
    this->price=param_price;
    this->name = new char[strlen(param_name) + 1];
    strcpy(this->name, param_name);

}
Product::Product(const Product &p) {
    this->code = p.code;
    this->name = new char [strlen(p.name) + 1];
    strcpy(name, p.name);
    this->price = p.price;

}

Product::~Product(){
    if (this->name != nullptr) delete[] this->name;

}
Product& Product::operator=(const Product &p){
    if(this != &p)
    {
        this->code = p.code;
        this->name=new char[strlen(p.name) + 1];
        strcpy(this->name, p.name);
        this->price= p.price;

        return *this;
    }
}

int Product::get_code() const{
    return code;
}
int Product:: get_pret()const  {
    return price;
}
char *Product::get_nume()const {
    return name;
}
void Product::set_cod(int param_code){
    this->code=param_code;
}
void Product::set_pret(float param_price){
    this->price=param_price;
}
void Product::set_nume(char *param_name){
    this->name=new char[strlen(param_name) + 1];
    strcpy(this->name, param_name);
}

ostream& operator<<(ostream &os, Product& p){
    os << "name: " << p.name << " price: " << p.price << " code: " << p.code;
    return os;
}
bool Product::operator==(const Product&p){
    return(code == p.code && price == p.price && strcmp(name, p.name) == 0);
}
void Product::to_string() {
    std::cout << "Cod: " << this->get_code() << ", Nume: " << this->get_nume() << ", Pret: " << this->get_pret()
              << std::endl;
}




