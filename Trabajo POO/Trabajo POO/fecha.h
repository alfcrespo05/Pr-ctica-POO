#include "User.h"
class Fecha : public User {
	private:
	int day;
	int month;
	int year;
public:
	//Constructor
	Fecha(int day, int month, int year)
		: day(day), month(month), year(year) {
	}
	void calcularDiasRetraso(const Fecha& fechaDevolucion, const Fecha& fechaLimite) {
		int diasRetraso = 0;
		if (fechaDevolucion.year > fechaLimite.year ||
			(fechaDevolucion.year == fechaLimite.year && fechaDevolucion.month > fechaLimite.month) ||
			(fechaDevolucion.year == fechaLimite.year && fechaDevolucion.month == fechaLimite.month && fechaDevolucion.day > fechaLimite.day)) {
			// Cálculo simplificado de días de retraso
			diasRetraso = (fechaDevolucion.year - fechaLimite.year) * 365 +
				(fechaDevolucion.month - fechaLimite.month) * 30 +
				(fechaDevolucion.day - fechaLimite.day);
			setSancion(diasRetraso);
			if(sancion > 15) {
				sancion = 15; // Limitar la sanción máxima a 15
			}
		}
	}

};

#pragma once
