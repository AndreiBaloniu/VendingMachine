

#ifndef LAB9_10_PRODUCT_H
#define LAB9_10_PRODUCT_H
#include <iostream>
using namespace std;
class Product{
private :

    int code;
    char* name;
    int price;
public:
    Product();
    Product(int param_code, char* param_name, int param_price);
    Product(const Product &p);
    ~Product();
    Product& operator=(const Product &p);
    int get_code() const;
    int get_pret() const;
    char *get_nume() const;
    void set_cod(int param_code);
    void set_pret(float param_price);
    void set_nume(char *param_name);
    friend ostream& operator<<(ostream &os, Product& p);
    bool operator==(const Product&p);
    void to_string();

};


#endif //LAB9_10_PRODUCT_H
