#include "ConjuntoParticulas.h"
#include <ctime>
#include <assert.h>
#include <math.h>

void ConjuntoParticulas::Redimensiona (bool aumentar){
    
    int nuevo = capacidad + (aumentar?TAM_BLOQUE:-TAM_BLOQUE);

    Particula * aux = new Particula [nuevo];

    for (int i = 0; i < this->utiles; i++)
        aux[i] = this->set[i];

    delete [] this->set;
    
    this->set = aux;
    this->capacidad= nuevo;

}

ConjuntoParticulas::ConjuntoParticulas (){

	set = 0;
	capacidad = 0;
	utiles = 0;

}

ConjuntoParticulas::ConjuntoParticulas (int capacidad){

	this->capacidad = capacidad;
	set = new Particula [capacidad];

	this->utiles = capacidad;
        
        for (int i = 0; i < this->utiles; i++){
            Particula p;
            this->set[i] = p;
        }

}			
		
ConjuntoParticulas::ConjuntoParticulas (const ConjuntoParticulas &c){

    this->capacidad = c.get_capacidad();
    this->utiles = c.get_utiles();
        
    this->set = new Particula [capacidad];
	
    for (int i = 0; i < this->get_utiles(); i++)
        this->set[i] = c.set[i];
        
}

ConjuntoParticulas::~ConjuntoParticulas (){

	delete [] set;

}
	
int ConjuntoParticulas::get_capacidad () const{

	return capacidad;

}
int ConjuntoParticulas::get_utiles () const{

	return utiles;

}

void ConjuntoParticulas::set_utiles (int utiles){
    
    this->utiles = utiles;
    
}

void ConjuntoParticulas::AgregaParticula (Particula p){

	if (this->get_utiles() == this->get_capacidad())
		this->Redimensiona(true);

	this->set[utiles] = p;
        
        this->utiles++;

}

void ConjuntoParticulas::BorraParticula (int posicion){
    
    assert (posicion < this->get_utiles());

    	this->utiles = this->get_utiles() - 1;
    
	for (int i = posicion; i < utiles; i++)
		this->set[i] = this->set[i + 1];

	if (this->get_capacidad() - this->get_utiles() > TAM_BLOQUE)
		this->Redimensiona(false);

}
		
Particula ConjuntoParticulas::ObtieneParticula (int posicion) const{
    
    assert (posicion < this->get_utiles());

	return this->set[posicion];

}

void ConjuntoParticulas::ReemplazaParticula (int &posicion, Particula p){

    assert (posicion < this->get_utiles());
    
	this->set[posicion] = p;

}

void ConjuntoParticulas::Mover (int &ancho, int &alto){

	for (int i = 0; i < utiles; i++)
		this->set[i].Mover(alto, ancho);

}

void ConjuntoParticulas::GestionarColisiones (){
    
    while (utiles > MAX_MOVILES)
        BorraParticula(0);
    
    for (int i = 0; i < this->utiles; i++)
        for (int j = i + 1; j < this->utiles; j++)
            if (set[i].get_color() == set[j].get_color() && set[i].colision(set[j]))
                BorraParticula(j);
            else
                this->set[i].Rebota(set[j]);

}

void ConjuntoParticulas::Swap(ConjuntoParticulas &c){
    
    int aux_capacidad = this->capacidad;
    this->capacidad = c.get_capacidad();
    c.capacidad = aux_capacidad;
    
    int aux_utiles = this->utiles;
    this->utiles = c.get_utiles();
    c.utiles = aux_utiles;
    
    Particula * aux_set = this->set;
    this->set = c.set;
    c.set = aux_set;
    
}

ConjuntoParticulas& ConjuntoParticulas::operator= (const ConjuntoParticulas &c){
    
    ConjuntoParticulas aux (c);
    
    aux.Swap(*this);
                
    return *this;
    
}

ConjuntoParticulas ConjuntoParticulas::operator+ (const ConjuntoParticulas &p) const{
    
    ConjuntoParticulas aux(this->get_utiles() + p.get_utiles());
    
    int posicion = 0;
    
    for (int i = 0; i < this->get_utiles(); i++){
        aux.ReemplazaParticula(posicion, this->set[i]);
        posicion++;
    }
    
    for (int i = 0; i < p.get_utiles(); i++){
        aux.ReemplazaParticula(posicion, p.set[i]);
        posicion++;
    }

    return aux;
    
}

Particula &ConjuntoParticulas::operator[] (int indice){
    
    return set[indice];
    
}
