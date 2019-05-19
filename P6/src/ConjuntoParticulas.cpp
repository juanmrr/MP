#include "ConjuntoParticulas.h"
#include <ctime>

void ConjuntoParticulas::Redimensiona (bool aumentar){

	if (aumentar)
            this->capacidad = this->capacidad + TAM_BLOQUE;
	else
            this->capacidad = this->capacidad - TAM_BLOQUE;

        if (this->set != NULL){
            Particula * aux = new Particula [this->get_capacidad()];

            for (int i = 0; i < this->utiles; i++)
                    aux[i] = this->set[i];

            delete [] this->set;

            this->set = aux;
            
        }

}

ConjuntoParticulas::ConjuntoParticulas (){

	set = NULL;
	capacidad = 0;
	utiles = 0;

}

ConjuntoParticulas::ConjuntoParticulas (int capacidad){

	this->capacidad = capacidad;
	set = new Particula [capacidad];
		
	time_t t;

	this->utiles = rand() % capacidad;

}			
		
ConjuntoParticulas::ConjuntoParticulas (const ConjuntoParticulas &c){

	this->capacidad = c.get_capacidad();
	this->utiles = c.get_utiles();
	
	set = new Particula [capacidad];
	
	for (int i = 0; i < utiles; i++)
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

    	this->utiles = this->get_utiles() - 1;
    
	for (int i = posicion; i < utiles; i++)
		this->set[i] = this->set[i + 1];

	if (this->get_capacidad() - this->get_utiles() > TAM_BLOQUE)
		this->Redimensiona(false);

}
		
Particula ConjuntoParticulas::ObtieneParticula (int &posicion) const{

	return this->set[posicion];

}

void ConjuntoParticulas::ReemplazaParticula (int &posicion, Particula &p){

	this->set[posicion] = p;

}

void ConjuntoParticulas::Mover (int &ancho, int &alto){

	for (int i = 0; i < utiles; i++)
		this->set[i].Mover(alto, ancho);

}

void ConjuntoParticulas::GestionarColisiones (){

	for (int i = 0; i < utiles; i++)
		for (int j = i + 1; j < utiles; j++)
                    if (set[i].get_color() == set[j].get_color())
                        BorraParticula(j);
                    else
                        this->set[i].Rebota(set[j]);

}

ConjuntoParticulas& ConjuntoParticulas::operator= (const ConjuntoParticulas &c){
    
    if (this != &c){
        delete [] this->set;
        ConjuntoParticulas(c);
    }
    
    return *this;
    
}

ConjuntoParticulas ConjuntoParticulas::operator+ (const ConjuntoParticulas &p) const{
    
    ConjuntoParticulas aux(this->get_capacidad() + p.get_capacidad());
    
    for (int i = 0; i < this->get_utiles(); i++){
        aux.AgregaParticula(this->ObtieneParticula(i));
    }
    
    for (int i = 0; i < p.get_utiles(); i++){
        aux.AgregaParticula(p.ObtieneParticula(i));
    }
    
    return aux;
    
}

Particula &ConjuntoParticulas::operator[] (int indice){
    
    return set[indice];
    
}