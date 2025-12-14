#pragma once
#include <iostream>

/*
 * Clase simple de fecha (día/mes/año) para préstamos y licencias.
 */
class Fecha {
private:
    int day;
    int month;
    int year;

public:
    Fecha() : day(1), month(1), year(2000) {}
    Fecha(int day, int month, int year)
        : day(day), month(month), year(year) {
    }

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    // Devuelve true si this es posterior a other.
    bool esPosteriorA(const Fecha& other) const {
        if (year != other.year) return year > other.year;
        if (month != other.month) return month > other.month;
        return day > other.day;
    }

    // Diferencia aproximada en días (this - other).
    int diasDiferencia(const Fecha& other) const {
        return (year - other.year) * 365 +
            (month - other.month) * 30 +
            (day - other.day);
    }

    void imprimir() const {
        std::cout << day << "/" << month << "/" << year;
    }
};

