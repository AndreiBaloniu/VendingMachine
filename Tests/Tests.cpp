#include <cstring>
#include <cassert>
#include "Tests.h"
#include "../Entities/Product.h"
#include "../Entities/Money.h"
#include "../Repos/Repo.h"
#include "../Service/Service.h"

void test_Product(){
    char* nume=new char[20];
    strcpy(nume, "fanta");
    Product p(32,nume, 4);
    Money v1("bancnota", 5);
    Money v2("moneda", 1);
    assert(v1.get_value() == 5);
    assert(v2.get_value() == 1);
    assert(strcmp(v1.get_type(),"bancnota") == 0);
    assert(strcmp(v2.get_type(), "moneda") == 0);
    assert(p.get_pret()==4);
    assert(p.get_code()==32);
    assert(strcmp(p.get_nume(), nume)==0);
    char *num = new char[20];
    strcpy(num, "sprite");
    Product t(4,num,2);
    assert(strcmp(t.get_nume(),num)==0);
    assert(t.get_pret()==2);
    t.set_pret(5);
    assert(t.get_pret()==5);
    t.set_nume(nume);
    assert(strcmp(t.get_nume(),nume)==0);
    delete []nume;
    delete []num;

}
void test_repo(){
    char *nume = new char[10];
    strcpy(nume, "Coca Cola");
    Product p(12,nume,4);
    char *num = new char[10];
    strcpy(num, "Popcola");
    Product t(10,num,3);
    Repo<Product> repo;
    repo.add(p);
    assert(repo.size()==1);
    assert(repo.get(0).get_pret()==4);
    repo.add(t);
    assert(repo.size()==2);
    assert(strcmp(repo.get(1).get_nume(),num)==0);
    repo.remove(0);
    assert(repo.size()==1);
    assert(repo.get(0).get_pret()==3);
    delete []nume;
    delete []num;
}
void test_service(){
    clear_file("Products_test.txt");
    clear_file("Currencies_test.txt");
    Repo_file_product repo_Product("Products_test.txt");
    Repo_file_money repo_valuta("Currencies_test.txt");
    Service tonomat(repo_Product, repo_valuta);
    tonomat.add_product(1, (char*)"croissant", 10);
    tonomat.add_product(2, (char*)"ciocolata", 5);
    tonomat.add_product(3, (char*)"chips", 16);
    tonomat.add_currency("moneda", 0.1);
    tonomat.add_currency("bancnota", 1);
    tonomat.add_currency("bancnota", 5);
    assert(tonomat.find_produs(1, (char*)"croissant", 10) == true);
    assert(tonomat.find_produs(2, (char*)"ciocolata", 161) == false);
    assert(tonomat.find_valuta((char*)"bancnota", 5) == true);
    assert(tonomat.find_valuta((char*)"moneda", 0.5) == false);
    assert(tonomat.number_of_produse() == 3);
    assert(tonomat.number_of_valute() == 3);
    assert(tonomat.find_valuta((char*)"moneda", 0.1) == true);
    tonomat.remove_val_by_index(0);
    assert(tonomat.number_of_valute() == 2);
    assert(tonomat.find_valuta((char*)"moneda", 0.1) == false);
    tonomat.update_produs(1, 10, (char*)"updated", 55);
    assert(tonomat.get_produs(1).get_code() == 10);
    assert(tonomat.get_produs(1).get_pret() == 55);
    assert(strcmp(tonomat.get_produs(1).get_nume(), "updated") == 0);
//    tonomat.remove_by_nume("Product1");
//    tonomat.remove_by_nume("nume_modificat");
//    tonomat.remove_by_nume("Product3");
//    assert(tonomat.number_of_produse() == 0);
//    tonomat.add_products(1, (char*)"test", 10, 5);
//    assert(tonomat.number_of_produse() == 5);
    vector<double> rest = tonomat.calculeaza_rest(21);
    assert(rest[0] == 5);
    assert(rest[1] == 5);
    assert(rest[2] == 5);
    assert(rest[3] == 5);
    assert(rest[4] == 1);
}
void test_all() {
    test_service();
    test_Product();
    test_repo();
}