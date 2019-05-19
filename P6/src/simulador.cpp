#include "ConjuntoParticulas.h"
#include "miniwin.h"
#include "definiciones.h"

Simulador::Simulador (ConjuntoParticulas p1, ConjuntoParticulas p2, int ancho, int alto){

	fijas = p1;
	moviles = p2;
	this->ancho = ancho;
	this->alto = alto;

	vredimensiona(ancho, alto);
}

Simulador::~Simulador(){

	vcierra();
	fijas.~ConjuntoParticulas();
        moviles.~ConjuntoParticulas();

}

void Simulador::set_fijas (ConjuntoParticulas &p){
	
	this->fijas = p;

}

void Simulador::set_moviles (ConjuntoParticulas &p){

	this->moviles = p;

}

ConjuntoParticulas Simulador::get_fijas (){

	return this->fijas;

}

ConjuntoParticulas Simulador::get_moviles (){

	return this->moviles;

}

void Simulador::Pintar_fijas (){

	int N = this->fijas.get_utiles();
    	Particula p;

    	for (int i = 0; i < N; i++) {
        	p = this->fijas.ObtieneParticula(i);
        	color(p.get_color());
        	rectangulo_lleno(p.get_x() - ANCHO_RECTANGULO, p.get_y() + ALTO_RECTANGULO, p.get_x() + ANCHO_RECTANGULO, p.get_y() - ALTO_RECTANGULO);
   	 }
}

void Simulador::Pintar_moviles (){

	int N = this->moviles.get_utiles();
    	Particula p;

    	for (int i = 0; i < N; i++) {
        	p = this->moviles.ObtieneParticula(i);
        	color(p.get_color());
        	circulo_lleno(p.get_x(), p.get_y(), RADIO);
   	 }
}
	
void Simulador::Pintar (int t){

	Pintar_moviles();
	Pintar_fijas();

	refresca();
	espera(t);

}

void Simulador::Rebotes (){

	for (int i = 0; i < this->fijas.get_utiles(); i++)
		for (int j = i + 1; j < this->moviles.get_utiles(); j++)
                    this->fijas.ObtieneParticula(i).Rebota(moviles.ObtieneParticula(j));

}

void Simulador::Step (){

	int N = this->moviles.get_utiles();

	for (int i = 0; i < N; i++){
		this->moviles.Mover(ancho, alto);
		this->moviles.GestionarColisiones();
	}

	Rebotes();

}

void Simulador::AgregaFija(){
    
    Particula p;
    
    this->fijas.AgregaParticula(p);
    
}

void Simulador::AgregaMovil(){
    
    Particula p;
    
    this->moviles.AgregaParticula(p);
    
}

void Simulador::Regenera(){
    
    int capacidadFija, capacidadMovil;
    
    capacidadFija = this->fijas.get_capacidad();
    capacidadMovil = this->moviles.get_capacidad();
    
    this->fijas.~ConjuntoParticulas();
    this->moviles.~ConjuntoParticulas();
    
    this->fijas = ConjuntoParticulas(capacidadFija);
    this->moviles = ConjuntoParticulas(capacidadMovil);
    
}