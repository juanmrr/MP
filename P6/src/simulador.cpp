#include "ConjuntoParticulas.h"
#include "miniwin.h"
#include "definiciones.h"
#include "simulador.h"

Simulador::Simulador (ConjuntoParticulas p1, ConjuntoParticulas p2, int ancho, int alto) : fijas(p1), moviles(p2), ancho(ancho), alto(alto) {

    vredimensiona (ancho, alto);

}

Simulador::~Simulador(){

    vcierra();

}

void Simulador::set_fijas (ConjuntoParticulas &p){
	
	this->fijas = p;

}

void Simulador::set_moviles (ConjuntoParticulas &p){

	this->moviles = p;

}

ConjuntoParticulas Simulador::get_fijas () const{

	return this->fijas;

}

ConjuntoParticulas Simulador::get_moviles () const{

	return this->moviles;

}

void Simulador::Pintar_fijas (){

	int N = this->fijas.get_utiles();
    	Particula p;

    	for (int i = 0; i < N; i++) {
        	p = this->fijas.ObtieneParticula(i);
        	color(p.get_color());
        	rectangulo_lleno(p.get_x() - ANCHO_RECTANGULO, p.get_y() - ALTO_RECTANGULO, p.get_x() + ANCHO_RECTANGULO, p.get_y()+ ALTO_RECTANGULO);
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
    
    borra();
    Pintar_fijas();
    Pintar_moviles();

    refresca();
    espera(t);

}

void Simulador::Rebotes (){
    
    Particula m, f;
    bool rebotado;

	for (int i = 0; i < this->moviles.get_utiles(); i++){
            rebotado = false;
            m = moviles.ObtieneParticula(i);
            for (int j = 0; j < this->fijas.get_utiles() && !rebotado; j++){
                f = fijas.ObtieneParticula(j);
                rebotado = f.colision(m);
                if (rebotado){
                    f.Rebota(m);
                    if (m.get_color() == f.get_color()){
                        Particula p(m);
                        p.set_x(fmod(rand(), MIN_X));
                        p.set_y(fmod(rand(), MIN_Y));
                        this->moviles.AgregaParticula(p);
                    }else
                        this->moviles.BorraParticula(i);
                }
            }
        }

}

void Simulador::Step (){

        this->moviles.Mover(ancho, alto);
	this->moviles.GestionarColisiones();

	//Rebotes();

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
    
    this->fijas = ConjuntoParticulas(capacidadFija);
    this->moviles = ConjuntoParticulas(capacidadMovil);
    
}