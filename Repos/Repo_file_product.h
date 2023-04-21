//
// Created by Baluta on 10.05.2022.
//

#ifndef LAB9_10_REPO_FILE_PRODUCT_H
#define LAB9_10_REPO_FILE_PRODUCT_H
#include "../Entities/Product.h"
#include "Repo.h"
#include "../utils.h"
#include <cstring>
#include <fstream>
#include <iostream>

class Repo_file_product : public Repo<Product> {
private:
    char* filename = nullptr;
    vector<Product> products;

public:
    Repo_file_product();
    Repo_file_product(const char* filename);
    void add(Product& p);
    bool find(Product& p);
    void update(int index, Product& nou);
    void remove(int index);
    void remove_product(Product& p);
    Product get(int index);
    vector<Product> get_all();
    unsigned int size();
    Repo_file_product& operator=(const Repo_file_product& r);
    void save_file();
    ~Repo_file_product();
};

inline Repo_file_product::Repo_file_product() {
    this->filename = new char[10];
    products.reserve(10);
}

inline Repo_file_product::Repo_file_product(const char* file_n) {
    this->filename = new char[strlen(file_n) + 1];
    strcpy_s(this->filename, strlen(file_n) + 1, file_n);
    ifstream f(filename);
    if (!f) cout << "Eroare la deschiderea fisierului!";
    if (file_is_empty(f)) {
        int altpret;
        int altcod;
        char* altnume = new char[10];
        f >> altcod >> altnume >> altpret;
        delete[] altnume;
        while (!f.eof()) {
            int cod, pret;
            char* nume = new char[10];
            f >> cod >> nume >> pret;
            Product p(cod, nume, pret);
            this->products.push_back(p);
            delete[] nume;
        }
    }
    else {
        while (!f.eof()) {
            int cod, pret;
            char* nume = new char[10];
            f >> cod >> nume >> pret;
            Product p(cod, nume, pret);
            this->products.push_back(p);
            delete[] nume;
        }
    }
    f.close();
}

inline void Repo_file_product::save_file() {
    ofstream g;
    g.open(this->filename);
    if (!g) cout << "Eroare la deschidere fisier";
    if (products.size() > 0) {
        vector<Product>::iterator it;
        for (it = products.begin(); it < products.end() - 1; it++) {
            Product p = *it;
            g << p.get_code() << ' ' << p.get_nume() << ' ' << p.get_pret() << '\n';
        }
        it = products.end() - 1;
        Product p2 = *it;
        g << p2.get_code() << ' ' << p2.get_nume() << ' ' << p2.get_pret();
    }
    g.close();
}

inline void Repo_file_product::add(Product& p) {
    this->products.push_back(p);
    this->save_file();
}


inline void Repo_file_product::update(int index, Product& nou) {
    this->products[index] = nou;
    this->save_file();
}

inline void Repo_file_product::remove(int index) {
    Product p = products[index];
    vector<Product>::iterator it = std::find(products.begin(), products.end(), p);
    if (it != products.end()) products.erase(it);
    this->save_file();
}

inline void Repo_file_product::remove_product(Product& p) {
    vector<Product>::iterator it = std::find(products.begin(), products.end(), p);
    if (it != products.end()) products.erase(it);
    this->save_file();
}

inline Product Repo_file_product::get(int index) {
    return products[index];
}

inline vector<Product> Repo_file_product::get_all() {
    return products;
}

inline bool Repo_file_product::find(Product& p) {
    vector<Product>::iterator it = std::find(products.begin(), products.end(), p);
    if (it != products.end())
        return true;
    return false;
}

inline unsigned int Repo_file_product::size() {
    return products.size();
}

inline Repo_file_product& Repo_file_product::operator=(const Repo_file_product& r) {
    if (this != &r) {
        this->products = r.products;
        this->filename = r.filename;
    }
    this->save_file();
    return *this;
}

inline Repo_file_product::~Repo_file_product() {
    fstream f(filename);
    if (f.is_open())
        f.close();
}

#endif //LAB9_10_REPO_FILE_PRODUCT_H
