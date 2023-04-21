//
// Created by Baluta on 25.05.2022.
//

#ifndef LAB9_10_VALUTAVALIDATOR_H
#define LAB9_10_VALUTAVALIDATOR_H


class ValutaValidator{
private:
    double underLimitValue{};
    double upperLimitValue{};
public:
    ValutaValidator();
    ValutaValidator(double underLimitValue, double upperLimitValue);
    bool validate(double valoare);
};


#endif //LAB9_10_VALUTAVALIDATOR_H
