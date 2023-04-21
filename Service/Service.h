
#ifndef LAB9_10_SERVICE_H
#define LAB9_10_SERVICE_H

#include "../Repos/Repo_file_money.h"
#include "../Repos/Repo_file_product.h"
#include "../Entities/Money.h"
#include "../Entities/Product.h"

class Service{
private:
    Repo_file_money repo_currencies;
    Repo_file_product repo_products;
public:
    Service();
    Service(const Service& t);
    Service(const Repo_file_product& repo_produs, const Repo_file_money& repo_valuta);

    void add_product(int cod, char* nume, int pret);
    void add_products(int cod, char* nume, int pret, int nr_prod);
    void add_currency(const char* tip, double valoare);
    void add_currencies(const char* tip, double valoare, int nr_val);

    bool find_produs(int cod, char* nume, int pret);
    bool find_by_code(int cod);
    bool find_valuta(char* tip, double valoare);

    int update_produs(int index, int cod,char* nume, int pret);
    int update_valuta(int index,char* tip, double valoare);

    void remove_prod_by_index(int index);
    void remove_produs(Product& p);
//    void remove_by_nume(const char* nume);
    void remove_val_by_index(int index);
    void remove_valuta(Money& v);

    Product get_produs(int index);
    Money get_valuta(int index);

    Product return_produs_by_cod(int cod);

    vector<Product> get_produse();
    vector<Money> get_valute();

    size_t number_of_produse();
    size_t number_of_valute();

    vector<double> calculeaza_rest(int suma);

    ~Service();
};


#endif //LAB9_10_SERVICE_H
