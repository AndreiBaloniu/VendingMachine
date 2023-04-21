
#include <iostream>
#include "../Exceptions/PositionExceptions.h"
#include "UI.h"
#include "../Exceptions/NoProductException.h"
#include "../Exceptions/ValutaExceptions.h"
#include "../Exceptions/InvalidPriceException.h"
#include "../Exceptions/InvalidCodeException.h"
#include "../Exceptions/NoRangeException.h"

using namespace std;

UI::UI() {
    Service tonomat;
}

UI::UI(Service& tonomat) {
    this->tonomat = tonomat;
}

UI::~UI()= default;

void print_menu() {
    cout << "1. Meniu produse." << endl;
    cout << "2. Meniu valuta." << endl;
    cout << "3. Afiseaza produsele din tonomat." << endl;
    cout << "4. Cumpara un produs." << endl;
    cout << "0. Inchidere." << endl;
}

void print_menu_produs() {
    cout << "1. Adauga produs." << endl;
    cout << "2. Sterge produs." << endl;
    cout << "3. Update produs." << endl;
    cout << "4. Afisare produse." << endl;
    cout << "5. Search produs." << endl;
    cout << "6. Numar produse." << endl;
    cout << "7. Adauga mai multe produse de acelasi tip." << endl;
    cout << "0. Inchidere" << endl;
}

void print_menu_valuta() {
    cout << "1. Adauga valuta." << endl;
    cout << "2. Sterge valuta." << endl;
    cout << "3. Update valuta." << endl;
    cout << "4. Search valuta." << endl;
    cout << "5. Afisare valute." << endl;
    cout << "6. Numar valute." << endl;
    cout << "7. Adauga mai multe valute de acelasi tip." << endl;
    cout << "0. Inchidere." << endl;
}


void UI::add_produs() {
    cout << "Introduceti codul produsului: ";
    int cod;
    cin >> cod;
    cout << "Introduceti numele produsului: ";
    char* nume = new char[10];
    cin >> nume;
    int pret;
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    try{
        this->pv.validate(pret, cod);
        this->tonomat.add_product(cod, nume, pret);}
    catch(InvalidPriceException* ex){
        cout << ex->what() << endl;
    }
    catch(InvalidCodeException* ex){
        cout<< ex->what()<<endl;
    }
    catch(...){
        cout << "Error!" << endl;
        terminate();
    }
    delete[] nume;
}

void UI::add_multiple_produs() {
    cout << "Introduceti numarul de produse pe care doriti sa le adaugati: ";
    int nr_prod;
    cin >> nr_prod;
    cout << "Introduceti codul produsului: ";
    int cod;
    cin >> cod;
    cout << "Introduceti numele produsului: ";
    char* nume = new char[10];
    cin >> nume;
    int pret;
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    this->tonomat.add_products(cod, nume, pret, nr_prod);
    delete[] nume;
}

void UI::update_produs() {
    int  i, cod, pret;
    char* nume = new char[10];
    cout << "Introduceti pozitia produsului pe care doriti sa il actualizati: "; cin >>  i;
    cout << "Introduceti noul cod al produsului: "; cin >> cod;
    cout << " Introduceti noul nume al produsului: "; cin >> nume;
    cout << "Introduceti noul pret al produsului: "; cin >> pret;
    try{this->tonomat.update_produs(i-1, cod, nume, pret);}
    catch(PositionExceptions* exception){cout << exception->what() << endl;}
//    if (!(this->tonomat.update_produs( i - 1, cod, nume, pret)))
//        cout << "La pozitia data nu exista nicio entitate!" << endl;
    delete[] nume;
}

void UI::remove_produs() {
    cout << "Introduceti pozitia produsului pe care doriti sa il stergeti: ";
    int  i;
    cin >>  i;
    try{this->tonomat.remove_prod_by_index( i - 1);}
    catch(PositionExceptions* exception){cout << exception->what() << endl;}

}

//void UI::remove_by_nume() {
//    cout << "Introduceti numele produsului pe care doriti sa il stergeti: ";
//    char* nume = new char[10];
//    cin >> nume;
//    this->tonomat.remove_by_nume(nume);
//}

void UI::search_produs() {
    cout << "Introduceti codul produsului: ";
    int cod;
    cin >> cod;
    cout << "Introduceti numele produsului: ";
    char* nume = new char[10];
    cin >> nume;
    int pret;
    cout << "Introduceti pretul produsului: ";
    cin >> pret;
    if (this->tonomat.find_produs(cod, nume, pret)) cout << "Produsul exista" << endl;
    else cout << "Produsul nu exista" << endl;
}

void UI::get_all_produse() {
    std::vector<Product> entities = this->tonomat.get_produse();
    for (int i = 0; i < entities.size(); i++) {
        cout << "Product " << i + 1 << ": ";
        entities[i].to_string();
    }
}

void UI::number_of_produse() {
    cout << "Exista " << this->tonomat.number_of_produse() << " entitati!" << endl;
}

void UI::add_valuta() {
    cout << "Introduceti tipul valutei(moneda/bancnota): ";
    char* tip = new char[10];
    cin >> tip;
    cout << "Introduceti valoarea valutei: ";
    float valoare;
    cin >> valoare;
    try{this->vv.validate(valoare);
    this->tonomat.add_currency(tip, valoare);}
    catch(NoRangeException* ex){
        cout<<ex->what()<<endl;
    }

    catch(...){
        cout << "Error!" << endl;

    }
    delete[] tip;
}

void UI::add_multiple_valuta() {
    cout << "Introduceti numarul de valute pe care doriti sa le adaugati: ";
    int nr_val;
    cin >> nr_val;
    cout << "Introduceti tipul valutei(moneda/bancnota): ";
    char* tip = new char[10];
    cin >> tip;
    cout << "Introduceti valoarea valutei: ";
    float valoare;
    cin >> valoare;
    this->tonomat.add_currencies(tip, valoare, nr_val);
    delete[] tip;
}

void UI::update_valuta() {
    int  i;
    float valoare;
    char* tip = new char[10];
    cout << "Introduceti pozitia valutei pe care doriti sa o actualizati: "; cin >>  i;
    cout << "Introduceti noul tip al produsului: "; cin >> tip;
    cout << " Introduceti noua valoarea a valutei: "; cin >> valoare;
//    if (!(this->tonomat.update_valuta( i - 1, tip, valoare))) cout << "La pozitia data nu exista nicio entitate!" << endl;
    try{this->tonomat.update_valuta(i-1,tip,valoare);}
    catch(ValutaExceptions* exception){cout << exception->what() << endl;}

    delete[] tip;
}

void UI::remove_valuta() {
    cout << "Introduceti pozitia valutei pe care doriti sa o stergeti: ";
    int  i;
    cin >>  i;
//    this->tonomat.remove_val_by_index( i - 1);
    try{this->tonomat.remove_val_by_index(i-1);}
    catch(ValutaExceptions* exception){cout << exception->what() << endl;}
}

void UI::search_valuta() {
    cout << "Introduceti tipul de valuta(moneda/bancnota): ";
    char* tip = new char[10];
    cin >> tip;
    cout << "Introduceti valoarea valutei: ";
    float valoare;
    cin >> valoare;
    if (this->tonomat.find_valuta(tip, valoare)) cout << "Valuta exista" << endl;
    else cout << "Valuta nu exista" << endl;
}

void UI::get_all_valute() {
    std::vector<Money> entities = this->tonomat.get_valute();
    for (int i = 0; i < entities.size(); i++) {
        cout << "Valuta " << i + 1 << ": ";
        entities[i].to_string();
    }
}

void UI::number_of_valute() {
    cout << "Exista " << this->tonomat.number_of_valute() << " produse!" << endl;
}

void UI::buy_product() {
    cout << "Introduceti codul produsului pe care doriti sa il cumparati: ";
    int cod; cin >> cod;
    try{this->tonomat.find_by_code(cod);
        cout << "Produsul a fost gasit!" << '\n';
        Product p = this->tonomat.return_produs_by_cod(cod);
        cout << "Pretul produsului este " << p.get_pret() << " lei. Introduceti o suma de bani: " << '\n';
        int suma; cin >> suma;
        if (suma < p.get_pret()) cout << "Suma introdusa nu este suficienta!" << '\n';
        else if (suma == p.get_pret()) {
            cout << "Tranzactie reusita!" << '\n';
            this->tonomat.remove_produs(p);
        }
        else {
            vector <double> rezultat = this->tonomat.calculeaza_rest(suma - p.get_pret());
            cout << "Restul dumneavoastra este: " << '\n';
            for (double i : rezultat) {
                if (i > 1) cout << i << " lei" << '\n';
                else if(i == 1) cout << "1 leu " << '\n';
                else if (i < 1) cout << i << " bani" << '\n';
            }
            this->tonomat.remove_produs(p);
        }}
    catch(NoProductException* exception)
        {cout<<exception->what()<<endl;
        }
}

void UI::run_menu_produse() {
    int optiune;
    do {
        print_menu_produs();
        cout << "Introduceti optiunea: ";
        cin >> optiune;
        switch (optiune) {
            case 1:
            {
                add_produs();
                break;
            }
            case 2:
            {
                remove_produs();
                break;
            }
            case 3:
            {
                update_produs();
                break;
            }
//            case 8:
//            {
//                remove_by_nume();
//                break;
//            }
            case 4:
            {
                get_all_produse();
                break;
            }
            case 5:
            {
                search_produs();
                break;
            }
            case 6:
            {
                number_of_produse();
                break;
            }
            case 7:
            {

                add_multiple_produs();
                break;
            }
        }
    } while (optiune != 0);
}

void UI::run_menu_valuta() {
    int optiune;
    do {
        print_menu_valuta();
        cout << "Introduceti optiunea: ";
        cin >> optiune;
        switch (optiune) {
            case 1:
            {
                add_valuta();
                break;
            }
            case 2:
            {
                remove_valuta();
                break;
            }
            case 3:
            {
                update_valuta();
                break;
            }
            case 4:
            {
                search_valuta();
                break;
            }
            case 5:
            {
                get_all_valute();
                break;
            }
            case 6:
            {
                number_of_valute();
                break;
            }
            case 7:
            {

                add_multiple_valuta();
                break;
            }
        }
    } while (optiune != 0);
}

void UI::run_menu() {
    int optiune;
    do {
        print_menu();
        cout << "Introduceti optiunea: ";
        cin >> optiune;
        switch (optiune) {
            case 1:
            {
                run_menu_produse();
                break;
            }
            case 2:
            {
                run_menu_valuta();
                break;
            }
            case 3: {
                get_all_produse();
                break;
            }
            case 4: {
                buy_product();
                break;
            }
        }
    } while (optiune != 0);
}

