#include <iostream>

#include <vector>

#include "productos.h"

using namespace std;

class Compra{
	
	protected:
		
		Producto productoComprado;
		
		string fechaCompra;
		
		string metodoDePago;
		
		string idCompra;
		
		string direccionCompra;
		
	public:
		
		void agregarCompra(Producto _productoComprado, string _fechaCompra, string _metodoDePago, string _direccionCompra);
		
		void guardarEnArchivos(string usuarioComprador);
		
		Producto getProductoComprado();
		
		string getFechaCompra();
		
		string getMetodoDePago();
		
		string getDireccionCompra();
		
		
	
};

void Compra::agregarCompra(Producto _productoComprado, string _fechaCompra, string _metodoDePago, string _direccionCompra){
	
	productoComprado = _productoComprado;
	
	fechaCompra = _fechaCompra;
	
	metodoDePago = _metodoDePago;
	
	direccionCompra = _direccionCompra;
}

void Compra::guardarEnArchivos(string usuarioComprador){
	
	string rutaGuardadoArchivos = "../Cuentas/" + usuarioComprador + "/datos_productos_comprados.csv";
	
	ofstream guardadoArchivos;
	
	guardadoArchivos.open(rutaGuardadoArchivos, ios::app);
	
	guardadoArchivos << endl << productoComprado.getNombre() << ";" << productoComprado.getPrecio() << ";" << metodoDePago << ";" << fechaCompra << ";" << direccionCompra << ";" << productoComprado.getID();
	
	guardadoArchivos.close();
	
}

Producto Compra::getProductoComprado(){
	
	return productoComprado;
	
}

string Compra::getFechaCompra(){
	
	return fechaCompra;
}

string Compra::getMetodoDePago(){
	
	return metodoDePago;
}

string Compra::getDireccionCompra(){
	
	return direccionCompra;
}

