#ifndef PARTICULA_H
#define PARTICULA_H

#include "definiciones.h"
#include <ctime>
#include <cmath>
#include "miniwin.h"

using namespace miniwin;

const int RADIO = 10;

class Particula {

private: 

	float x;
	float y;
	float dx;
	float dy;
	Color c;

public:

	Particula();
	Particula(float x, float y);

	float get_x() const;
	float get_y() const;
	float get_dx() const;
	float get_dy() const;
	Color get_color() const;
	void set_x (float x);
	void set_y (float y);
	void set_dx (float dx);
	void set_dy (float dy);
	void set_color (Color c);

	float distancia (const Particula &p);
	bool colision (const Particula &p);
	void Mover (int alto, int ancho);
	void Rebota (Particula otra);

};

#endif
