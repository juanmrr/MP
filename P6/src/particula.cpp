#include "particula.h"

Particula::Particula(){

	this->x = fmod(rand(), MIN_X);
	this->y = fmod(rand(), MIN_Y);
	
	float velocidad = fmod(rand(), MAX_VEL);

	this->dx = velocidad;
	this->dy = velocidad;

	this->c = static_cast <Color>((rand() % 8) + 1);

}

Particula::Particula(float x, float y){

	this->x = x;
	this->y = y;
	this->dx = 1.0;
	this->dy = 1.0;
	this->c = ROJO;

}

float Particula::get_x() const{
	return x;
}

float Particula::get_y() const{
	return y;
}

float Particula::get_dx() const{
	return dx;
}

float Particula::get_dy() const{
	return dy;
}

Color Particula::get_color() const{
	return c;
}

void Particula::set_x (float x){
	this->x = x;
}

void Particula::set_y (float y){
	this->y = y;
}

void Particula::set_dx (float dx){
	this->dx = dx;
}

void Particula::set_dy (float dy){
	this->dy = dy;
}

void Particula::set_color (Color c){
	this->c = c;
}

float Particula::distancia (const Particula &p){

	float distancia;

	distancia = sqrt(pow(this->x - p.get_x(), 2) + pow(this->y - p.get_y(), 2));

	return distancia;

}

bool Particula::colision (const Particula &p){

	float dist;
	bool colision = false;
	
	dist = this->distancia(p);

	if (dist <= UMBRAL)
		colision = true;

	return colision;

}

void Particula::Mover(int alto, int ancho) {

   const float factor = 0.85;
   this->set_x(this->get_dx() + this->get_x());
   this->set_y(this->get_dy() + this->get_y());
   if (this->get_x() > ancho - RADIO) {
      this->set_dx(-this->get_dx() * factor);
      this->set_x(ancho - RADIO);
   }
    else if (this->get_x() < RADIO) {
      this->set_dx(-this->get_dx() * factor);
      this->set_x(RADIO);
   }
    else if (this->get_y() > alto - RADIO) {
      this->set_dy(-this->get_dy() * factor);
      //P.dy += 0.1;
      this->set_y(alto - RADIO);
   }
    else if (this->get_y() < RADIO) {
      //P.dy += 0.1;
      this->set_dy(-this->get_dy() * factor);
      this->set_y(RADIO);
   }
   
   // si queremos simular gravedad, incrementar dy
  // P.dy += 0.1;
}

void Particula::Rebota (Particula &otra) {

	if (this->colision(otra)){
            this->dx = -this->dx;
            this->dy = -this->dy;
            otra.set_dx(-otra.get_dx());
            otra.set_dy(-otra.get_dy());
	}
}
