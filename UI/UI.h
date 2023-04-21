
#ifndef LAB9_10_UI_H
#define LAB9_10_UI_H


#include "../Service/Service.h"
#include "../Validations/ProductValidator.h"
#include "../Validations/ValutaValidator.h"

class UI {
private:
    Service tonomat;
    ProductValidator pv;
    ValutaValidator vv;
    void add_produs();
    void add_multiple_produs();
    void remove_produs();
    void remove_by_nume();
    void update_produs();
    void search_produs();
    void get_all_produse();
    void number_of_produse();
    void add_valuta();
    void add_multiple_valuta();
    void remove_valuta();
    void update_valuta();
    void search_valuta();
    void get_all_valute();
    void number_of_valute();
    void run_menu_produse();
    void run_menu_valuta();
    void buy_product();

public:
    UI();
    UI(Service& tonomat);
    void run_menu();
    ~UI();
};
#endif //LAB9_10_UI_H
