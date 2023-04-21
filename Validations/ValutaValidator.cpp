
#include "ValutaValidator.h"
#include "../Exceptions/NoRangeException.h"


ValutaValidator::ValutaValidator() = default;

ValutaValidator::ValutaValidator(double underLimitValue, double upperLimitValue) {
    this->underLimitValue = underLimitValue;
    this->upperLimitValue = upperLimitValue;
}

bool ValutaValidator::validate(double valoare) {
    if(valoare <= 0 || valoare >500)
        throw new NoRangeException;
    return true;
}