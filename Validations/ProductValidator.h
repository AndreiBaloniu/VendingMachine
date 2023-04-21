#pragma once

class ProductValidator{
private:
    int underLimitName{};
    int upererLimitName{};
    int underLimitPrice{};
    int upperLimitPrice{};
public:
    ProductValidator();
    explicit ProductValidator(int paramUnderLimitPrice);
    static bool validate(int price, int id);

};