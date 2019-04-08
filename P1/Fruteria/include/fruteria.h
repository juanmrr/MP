#ifndef _CILINDRO_H
#define _CILINDRO_H

struct Producto
{
    string nombre;
    int peso; // en gramos
    float precio_kg;
	Producto(string nombre, int peso, float precio_kg){
		this->nombre = nombre;
		this->peso = peso;
		this->precio_kg = precio_kg;
	}
};

struct Compra
{
    static const int MAX = 10;
    Producto lista[MAX];
};

Producto creaProducto(string nombre, int peso, float precio);

void incrementarPrecios(Compra & c, int k);

void listarCompra(const Compra & c);

void obtenerImporteYPeso(const Compra & c, float & precio, float & peso);

void mostrarTicketCompra(const Compra & c);

string productoToString(Producto a);

#endif
