#ifndef SIMULADOR_H
#define SIMULADOR_H

class Simulador{

private:

	ConjuntoParticulas fijas;
	ConjuntoParticulas moviles;
	int ancho, alto;

	void Pintar_fijas ();
	void Pintar_moviles ();

public:

	Simulador (ConjuntoParticulas p1, ConjuntoParticulas p2, int ancho, int alto);
	~Simulador ();

	void set_moviles (ConjuntoParticulas &p);
	void set_fijas (ConjuntoParticulas &p);

	ConjuntoParticulas get_fijas () const;
	ConjuntoParticulas get_moviles () const;

	void Pintar (int t);
	void Step ();
	void Rebotes ();
        void Step_colores ();
	void Rebotes_colores ();
        
        void AgregaFija();
        void AgregaMovil();
        void Regenera();

};

#endif
