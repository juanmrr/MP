#include<iostream>
#include<string>
#include<fruteria.h>

using namespace std;

// función para devolver los datos de un producto como un string
fruteria::string productoToString(Producto a)
{
    string rta;
    rta = a.nombre + "\t\t" + to_string(a.peso) + "\t" + to_string(a.precio_kg);
    return rta;
}

// crea una variable de tipo Producto y la devuelve
fruteria::Producto creaProducto(string nombre, int peso, float precio)
{

	Producto p(nombre, peso, precio);

	return p;
}

// incrementa el precio de cada producto en un k %
fruteria::void incrementarPrecios(Compra & c, int k)
{

	int porcentaje = k/100;

	for (int i = 0; i < MAX; i++){
		c.lista[i] = c.lista[i] * porcentaje + c.lista[i];
	}

}

// muestra el listado de productos comprados
fruteria::void listarCompra(const Compra & c)
{

	for(int i = 0; i < MAX; i++){
		productoToString(c.lista[i]);

}

// función que devuelve el importe total de la compra (sin IVA) y su peso (en kgs)
fruteria::void obtenerImporteYPeso(const Compra & c, float & precio, float & peso)
"

	for (int i = 0; i < MAX; i++){
		precio += c.lista[i].precio;
		peso += c.lista[i].peso;
	}

}

// función que muestra el "ticket" de compra según el formato sugerido
fruteria::void mostrarTicketCompra(const Compra & c)
{

	listarCompra(c);

	float precio = 0;
	int peso = 0;

	obtenerImporteYPeso(c, precio, peso);

	cout << "Subtotal: \t\t" << precio << endl;

	float iva = precio * 0.21;

	cout << "IVA(21%): \t\t" << iva << endl;

	float total = precio + iva;

	cout << "Total de la compra: " << total << endl;

	

}
