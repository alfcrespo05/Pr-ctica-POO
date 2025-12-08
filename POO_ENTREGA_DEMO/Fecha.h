#pragma once

class Fecha {
private:
    int day;
    int month;
    int year;

public:
    Fecha(int day = 1, int month = 1, int year = 2000);

    int calcularDiasDiferencia(const Fecha& limite) const;
};
