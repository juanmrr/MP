#ifndef CONJUNTOPARTICULAS_H
#define CONJUNTOPARTICULAS_H

#include "particula.h"
#include <iostream>

int const TAM_BLOQUE = 5;

class ConjuntoParticulas {

private:

	Particula *set;
	int capacidad;
	int utiles;

	void Redimensiona (bool aumentar);
        void Swap (ConjuntoParticulas &c);

public:

	ConjuntoParticulas ();
	ConjuntoParticulas (int capacidad);
	ConjuntoParticulas (const ConjuntoParticulas &c);
	~ConjuntoParticulas ();
	
	int get_capacidad () const;
	int get_utiles () const;
        
        void set_utiles (int utiles);

	void AgregaParticula (Particula p);
	void BorraParticula (int posicion);
	Particula ObtieneParticula (int posicion) const;
	void ReemplazaParticula (int &posicion, Particula p);
	void Mover (int &ancho, int &alto);
	void GestionarColisiones ();
        
        ConjuntoParticulas &operator= (const ConjuntoParticulas &c);
        ConjuntoParticulas operator+ (const ConjuntoParticulas &p) const;
        Particula &operator[] (int indice);

};

#endif
