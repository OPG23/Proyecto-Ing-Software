#include <iostream>

#include <regex>

#include <fstream>

#include "escribirEnPantalla.h"

using namespace std;

class Producto{
	
	protected:
		
		string nombre;
		
		string descripcion;
		
		string precio;
		
		int stock;
		
	public:
		
		producto();
		
		string getNombre();
		
		string getPrecio();
		
		string getDescripcion();
		
		int getStock();
		
		void agregarProducto(string _nombre, string _descripcion, string _precio, int _stock);
		
		void editarDatos(int ancho, string usuario);
		
		void guardarProductoEnArchivos(string usuario);
		
		void verificarCarpetaProducto(string usuario);
};

string Producto::getNombre(){
	
	return nombre;
	
}

string Producto::getPrecio(){
	
	return precio;
	
}

string Producto::getDescripcion(){
	
	return descripcion;
}

int Producto::getStock(){
	
	return stock;
	
}


void Producto::agregarProducto(string _nombre, string _descripcion, string _precio, int _stock){
	
	nombre = _nombre;
	
	descripcion = _descripcion;
	
	precio = _precio;
	
	stock = _stock;
}

void Producto::editarDatos(int ancho, string usuario){
	
	int op;
	
	textoNormal("1. Nombre.", ancho, true);
	
	textoNormal("2. Descripción.", ancho, true);
	
	textoNormal("3. Precio.", ancho, true);
	
	textoNormal("4. Stock", ancho, true);
	
	textoNormal("Ingrese el dato que desea modificar: ", ancho, false);
	
	cin >> op;
	
	switch(op){
		
		case 1:{
			
			string nuevoNombre;
			
			textoNormal("Ingrese el nuevo nombre: ", ancho, false);
			
			nombre = nuevoNombre;
			
			break;
		}
		
		case 2:{
			
			string nuevaDescripcion;
			
			textoNormal("Ingrese la nueva descripcion: ", ancho, false);
			
			getline(cin, nuevaDescripcion);
			
			descripcion = nuevaDescripcion;
			
			break;
		}
		
		case 3:{
			
			string nuevoPrecio;
			
			textoNormal("Ingrese el nuevo precio: ", ancho, false);
			
			cin >> nuevoPrecio;
			
			regex expresionRegularPrecioValido("^[0-9]+$");

			if(regex_match(nuevoPrecio, expresionRegularPrecioValido)){
				
				precio = nuevoPrecio;
			}else{
				
				textoNormal("Precio no valido.", ancho, true);
			}
			
			break;
		}
		
		case 4:{
			
			int nuevoStock;
			
			textoNormal("Ingrese el nuevo stock: ", ancho, false);
			
			cin >> nuevoStock;
			
			stock = nuevoStock;
			
			break;
		}
		
		default:{
			
			textoNormal("Opción no valida.", ancho, true);
			
			break;
		}
		
	}
	
	guardarProductoEnArchivos(usuario);
	
}

void Producto::verificarCarpetaProducto(string usuario){
	
	string comandoCMD;
	
	comandoCMD  = "if exist ../Productos/" + usuario + "/ (exit 1) else (exit 0)";
	
	int resultado = system(comandoCMD.c_str());
	
	if(resultado == 0){
		
		string comando2CMD = "mkdir ..\\Productos\\" + usuario;
		
		system(comando2CMD.c_str());
	}
	
}

void Producto::guardarProductoEnArchivos(string usuario){
	
	string ruta = "../Productos/" + usuario + "/" + nombre + ".csv";
	
	verificarCarpetaProducto(usuario);
	
	ofstream guardarProducto;
	
	guardarProducto.open(ruta);
	
	guardarProducto << "Nombre;Descripción;Precio;Stock";
	
	guardarProducto << endl << nombre << ";" << descripcion<< ";" << precio << ";" << stock;
	
	guardarProducto.close();
}
