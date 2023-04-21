
#ifndef LAB9_10_REPO_FILE_MONEY_H
#define LAB9_10_REPO_FILE_MONEY_H
#include "../Entities/Money.h"
#include "Repo.h"
#include "../utils.h"
#include <cstring>
#include <alg.h>
#include <iostream>

class Repo_file_money : public Repo<Money> {
private:
    char* filename = nullptr;
    vector<Money> currencies;

public:
    Repo_file_money();
    Repo_file_money(const char* filename);
    void add(Money& p);
    bool find(Money& p);
    void update(int index, Money& nou);
    void remove(int index);
    void remove_currencies(Money& v);
    Money get(int index);
    vector<Money> get_all();
    unsigned int size();
    Repo_file_money& operator=(const Repo_file_money& r);
    void save_file();
    ~Repo_file_money();
};

inline Repo_file_money::Repo_file_money() {
    this->filename = new char[10];
    this->currencies.reserve(10);
}

inline Repo_file_money::Repo_file_money(const char* file_n) {
    this->filename = new char[strlen(file_n) + 1];
    strcpy_s(this->filename, strlen(file_n) + 1, file_n);
    ifstream f(filename);
    if (!f) cout << "Eroare la deschidere fisier";
    if (file_is_empty(f)) {
        double altvaloare;
        char* alttip = new char[10];
        f >> alttip >> altvaloare;
        delete[] alttip;
        while (!f.eof()) {
            double valoare;
            char* tip = new char[10];
            f >> tip >> valoare;
            Money v(tip, valoare);
            this->currencies.push_back(v);
            delete[] tip;
        }
    }
    else {
        while (!f.eof()) {
            double valoare;
            char* tip = new char[10];
            f >> tip >> valoare;
            Money v(tip, valoare);
            this->currencies.push_back(v);
            delete[] tip;
        }
    }
    f.close();
}

inline void Repo_file_money::save_file() {
    ofstream g;
    g.open(this->filename);
    if (!g) cout << "Eroare la deschidere fisier";
    vector<Money>::iterator it;
    for (it = currencies.begin(); it < currencies.end() - 1; it++) {
        Money v = *it;
        g << v.get_type() << ' ' << v.get_value() << '\n';
    }
    it = currencies.end() - 1;
    Money v2 = *it;
    g << v2.get_type() << ' ' << v2.get_value();
    g.close();
}


inline void Repo_file_money::add(Money& p) {
    this->currencies.push_back(p);
    this->save_file();
}
inline bool Repo_file_money::find(Money& p) {
    vector<Money>::iterator it = std::find(currencies.begin(), currencies.end(), p);
    if (it != currencies.end())
        return true;
    return false;
}



inline void Repo_file_money::update(int index, Money& nou) {
    this->currencies[index] = nou;
    this->save_file();
}

inline void Repo_file_money::remove(int index) {
    Money p = currencies[index];
    vector<Money>::iterator it = std::find(currencies.begin(), currencies.end(), p);
    if (it != currencies.end()) currencies.erase(it);
    this->save_file();
}

inline void Repo_file_money::remove_currencies(Money& v) {
    vector<Money>::iterator it = std::find(currencies.begin(), currencies.end(), v);
    if (it != currencies.end()) currencies.erase(it);
    this->save_file();
}

inline Money Repo_file_money::get(int index) {
    return currencies[index];
}

inline vector<Money> Repo_file_money::get_all() {
    return currencies;
}

inline unsigned int Repo_file_money::size() {
    return currencies.size();
}

inline Repo_file_money& Repo_file_money::operator=(const Repo_file_money& r) {
    if (this != &r) {
        this->currencies = r.currencies;
        this->filename = r.filename;
    }
    return *this;
}

inline Repo_file_money::~Repo_file_money() {
    fstream f(filename);
    if (f.is_open())
        f.close();
}

#endif //LAB9_10_REPO_FILE_MONEY_H
