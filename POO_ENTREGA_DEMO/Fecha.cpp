#include "Fecha.h"

Fecha::Fecha(int d, int m, int y) : day(d), month(m), year(y) {}

int Fecha::calcularDiasDiferencia(const Fecha& f) const {
    return (year - f.year) * 365 +
        (month - f.month) * 30 +
        (day - f.day);
}
