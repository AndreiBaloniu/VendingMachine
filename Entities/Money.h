
#ifndef LAB9_10_MONEY_H
#define LAB9_10_MONEY_H


class Money {
private:
    char* type = nullptr;
    double value;
public:
    Money();
    Money(const char* param_type, double param_value);
    Money(const Money& v);
    void set_value(double param_value);
    void set_type(const char* param_tpye);
    double get_value();
    const char* get_type();
    ~Money();
    Money& operator=(const Money& v);
    bool operator== (const Money& v);
    void to_string();
};


#endif //LAB9_10_MONEY_H
