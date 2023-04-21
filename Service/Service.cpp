
#include "Service.h"
#include "../Exceptions/PositionExceptions.h"
#include "../Exceptions/NoProductException.h"
#include "../Exceptions/ValutaExceptions.h"

Service::Service() = default;

Service::Service(const Repo_file_product& repo_produs, const Repo_file_money& repo_valuta) {
    this->repo_products = repo_produs;
    this->repo_currencies = repo_valuta;
}

Service::Service(const Service& t) {
    this->repo_products = t.repo_products;
    this->repo_currencies = t.repo_currencies;
}

void Service::add_product(int cod, char* nume, int pret) {
    Product p(cod, nume, pret);
    this->repo_products.add(p);
}

void Service::add_products(int cod, char* nume, int pret, int nr_prod) {
    Product p(cod, nume, pret);
    for (int i = 0; i < nr_prod; i++) this->repo_products.add(p);
}

void Service::add_currency(const char* tip, double valoare) {
    Money v(tip, valoare);
    this->repo_currencies.add(v);
}

void Service::add_currencies(const char* tip, double valoare, int nr_val) {
    Money v(tip, valoare);
    for (int i = 0; i < nr_val; i++) this->repo_currencies.add(v);
}

bool Service::find_produs(int cod,char* nume, int pret) {
    Product p(cod, nume, pret);
    return this->repo_products.find(p);
}

bool Service::find_by_code(int cod) {
    for (Product& p : this->repo_products.get_all()) {
        if (p.get_code() == cod) return true;
    }
    throw new NoProductException;
}

bool Service::find_valuta(char* tip, double valoare) {
    Money v(tip, valoare);
    bool found = this->repo_currencies.find(v);
    return found;
}

int Service::update_produs(int index, int cod,char* nume, int pret) {
    if (index <= repo_products.size() && index >= 0) {
        Product p(cod, nume, pret);
        this->repo_products.update(index, p);
        return 1;
    }
    else throw new PositionExceptions;


}

int Service::update_valuta(int index,char* tip, double valoare) {
    if (index <= repo_products.size() && index >= 0) {
        Money v(tip, valoare);
        this->repo_currencies.update(index, v);
        return 1;
    }
    else throw new ValutaExceptions;
}

void Service::remove_prod_by_index(int index) {
    if (index <= repo_products.size() && index >= 0) this->repo_products.remove(index);
    else throw new PositionExceptions;
}

void Service::remove_produs(Product& p) {
    this->repo_products.remove_product(p);
}

void Service::remove_val_by_index(int index) {
    if (index <= repo_currencies.size() && index >= 0) this->repo_currencies.remove(index);
    else throw new ValutaExceptions;
}

void Service::remove_valuta(Money& v) {
    this->repo_currencies.remove_currencies(v);
}

//void Service::remove_by_nume(const char* nume) {
//    for (Product& p: repo_products.get_all()) {
//        if (strcmp(p.get_nume(), nume) == 0) remove_produs(p);
//    }
//}

Product Service::get_produs(int index) {
    return this->repo_products.get(index);
}

Money Service::get_valuta(int index) {
    return this->repo_currencies.get(index);
}

Product Service::return_produs_by_cod(int cod) {
    for (Product& p : this->repo_products.get_all())
        if (p.get_code() == cod) return p;
}

vector<Product> Service::get_produse() {
    return repo_products.get_all();
}

vector<Money> Service::get_valute() {
    return this->repo_currencies.get_all();
}

size_t Service::number_of_produse() {
    return this->repo_products.size();
}

size_t Service::number_of_valute() {
    return this->repo_currencies.size();
}

vector<double> Service::calculeaza_rest(int suma) {
    vector<double> valori;
    for (Money& v : this->repo_currencies.get_all()) {
        valori.push_back(v.get_value());
    }
    std::sort(valori.begin(), valori.end(), [](double a, double b) { return a > b; });
    int i = 0;
    double q = 0;
    int ok = 0;
    vector<double> rezultat;
    while (ok == 0 && i < valori.size()) {
        while (q + valori[i] <= suma) {
            q += valori[i];
            rezultat.push_back(valori[i]);
        }
        if (q == suma) ok = 1;
        i++;
    }
    return rezultat;
}

Service::~Service()= default;