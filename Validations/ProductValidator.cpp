
#include "ProductValidator.h"
#include "../Exceptions/NoProductException.h"
#include "../Exceptions/InvalidPriceException.h"
#include "../Exceptions/InvalidCodeException.h"
#include <iostream>

using namespace std;
//void ProductValidator::cv(int num) {
//    while(!(cin>>num))
//        {if(num <= 0)
//            cout<<"eroare";
//            cin.clear();
//            cin.ignore(123,'\n');
//            break;
//        }
//}
//
//ProductValidator::ProductValidator() = default;
ProductValidator::ProductValidator(int paramUnderLimitPrice) {

    this->underLimitPrice = paramUnderLimitPrice;

}

bool ProductValidator::validate(int price, int id) {

    if(price < 0)
        throw new InvalidPriceException;
//        cout<<"invalid";
    if(id < 0)
        throw new InvalidCodeException;
//        cout<<"negativ";

    return true;
}

ProductValidator::ProductValidator() = default;
