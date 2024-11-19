#include <iostream>

#include <vector>

#include "tarjetas.h"

#include <fstream>

#include "compras.h"

#include "direcciones.h"

using namespace std;

class Cuenta{
	
	protected:
		
		string usuario;
		
		string clave;
		
		string nombre;
		
		string correo;
		
		string celular;
		
		vector<Tarjeta> tarjetas;
		
		vector<Direccion> direcciones;
		
		vector<Producto> carritoCompras;
		
		vector<Producto> productosEnVenta;
		
		vector<Compra> productosComprados;
		
	
	public:
		
		Cuenta();
		
		void agregarDatos(string _usuario, string _clave, string _nombre, string _correo, string _celular);
		
		void agregarProductoCarrito(Producto producto);
		
		void eliminarProductoCarrito(Producto producto);
		
		void eliminarVariosProductosCarrito(vector<Producto> productosEliminar);
		
		void agregarProductoComprado(Compra compra);
		
		void guardarCuentaEnArchivo();
		
		void setDireccion(Direccion _direccion);
		
		void guardarDireccionArchivo(Direccion _direccion);
		
		void setTarjeta(Tarjeta _tarjeta);
		
		void guardarTarjetaArchivo(Tarjeta _tarjeta);
		
		void editarProductoVenta(Producto producto, int posicion);
		
		void agregarProductoEnVenta(Producto producto);
		
		void guardarProductoEnVentaArchivo(Producto producto);
		
		void editarClave(string nuevoDato);
		
		void editarCorreo(string nuevoDato);
		
		void editarCelular(string nuevoDato);
		
		void editarNombre(string nuevoDato);
		
		vector<Producto> getProductosEnVenta();
		
		vector<Direccion> getDireccion();
		
		vector<Producto> getCarritoCompras();
		
		vector<Compra> getProductosComprados();
		
		string getUsuario();
		
		string getClave();
		
		vector<Tarjeta> getTarjetas();
};

Cuenta::Cuenta(){
}


void Cuenta::agregarDatos(string _usuario, string _clave, string _nombre, string _correo, string _celular){
	
	usuario = _usuario;
		
	clave = _clave;
		
	nombre = _nombre;
		
	correo = _correo;
		
	celular = _celular;
	
}

void Cuenta::agregarProductoCarrito(Producto producto){
	
	carritoCompras.push_back(producto);
}

void Cuenta::eliminarProductoCarrito(Producto producto){
	
	for(int i = 0; i < carritoCompras.size(); i++){
		
		if(producto.getNombre() == carritoCompras[i].getNombre() && producto.getDescripcion() == carritoCompras[i].getDescripcion() && producto.getPrecio() == carritoCompras[i].getPrecio()){
			
			carritoCompras.erase(carritoCompras.begin() + i);
			
			break;
			
		}
	}
	
}

void Cuenta::eliminarVariosProductosCarrito(vector<Producto> productosEliminar){
	
	for(int i = 0; i < productosEliminar.size(); i++){
		
		eliminarProductoCarrito(productosEliminar[i]);
		
	}
	
}

void Cuenta::agregarProductoComprado(Compra compra){
	
	productosComprados.push_back(compra);
	
}

void Cuenta::guardarCuentaEnArchivo(){
	
	string comando2CMD = "mkdir ..\\Cuentas\\" + usuario;
	
	string rutaDatosUsuario = "../Cuentas/" + usuario + "/datos_cuenta.csv";
	
	string rutaDatosTarjeta = "../Cuentas/" + usuario + "/datos_tarjeta.csv";
	
	string rutaDatosCarrito = "../Cuentas/" + usuario + "/datos_carrito.csv";
	
	string rutaDatosDireccion = "../Cuentas/" + usuario + "/datos_direccion.csv";
	
	string rutaDatosProductosComprados = "../Cuentas/" + usuario + "/datos_productos_comprados.csv";
	
	string rutaDatosProductosEnVenta = "../Cuentas/" + usuario + "/datos_productos_venta.csv";
		
	system(comando2CMD.c_str());
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosUsuario, ios::app);
	
	registrosCuentas << "Nombre;Correo;Celular;Usuario;Clave";
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave;
	
	registrosCuentas.close();
	
	registrosCuentas.open(rutaDatosTarjeta, ios::app);
	
	registrosCuentas << "Numero Tarjeta;CVV de Tarjeta;Fecha De Vencimiento;Nombre De Tarjeta";
	
	if(tarjetas.size() > 0){
	
		registrosCuentas << endl << tarjetas[0].getNumeroTarjeta() << ";" << tarjetas[0].getCvvTarjeta() << ";" << tarjetas[0].getFechaVencimientoTarjeta() << ";" << tarjetas[0].getNombreTarjeta();
		
	}
	
	registrosCuentas.close();
	
	registrosCuentas.open(rutaDatosCarrito, ios::app);
	
	registrosCuentas.close();
	
	registrosCuentas.open(rutaDatosDireccion, ios::app);
	
	registrosCuentas << "Direccion Completa;Datos Adicionales;Puntos De Referencia";
	
	registrosCuentas.close();
	
	registrosCuentas.open(rutaDatosProductosComprados, ios::app);
	
	registrosCuentas << "Nombre Del Producto;Valor Transaccion;Medio De Pago;Fecha;Direccion De Entrega;ID Producto;ID Compra";
	
	registrosCuentas.close();
	
	registrosCuentas.open(rutaDatosProductosEnVenta, ios::app);
	
	registrosCuentas.close();
	
	
	
}

void Cuenta::setDireccion(Direccion _direccion){
	
	direcciones.push_back(_direccion);
}

void Cuenta::guardarDireccionArchivo(Direccion _direccion){
	
	string rutaDatosDireccion = "../Cuentas/" + usuario + "/datos_direccion.csv";
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosDireccion, ios::app);
	
	registrosCuentas << endl <<  _direccion.getDireccionCompleta() << ";" << _direccion.getDatosAdicionales() << ";" << _direccion.getPuntosDeReferencia();
	
}

void Cuenta::setTarjeta(Tarjeta _tarjeta){
	
	tarjetas.push_back(_tarjeta);
	
}

void Cuenta::guardarTarjetaArchivo(Tarjeta _tarjeta){
	
	string rutaDatosTarjeta = "../Cuentas/" + usuario + "/datos_tarjeta.csv";
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosTarjeta, ios::app);
	
	registrosCuentas << endl << _tarjeta.getNumeroTarjeta() << ";" << _tarjeta.getCvvTarjeta() << ";" << _tarjeta.getFechaVencimientoTarjeta() << ";" << _tarjeta.getNombreTarjeta();
	
}

void Cuenta::editarProductoVenta(Producto producto, int posicion){
	
	productosEnVenta[posicion] = producto;
		
}

void Cuenta::guardarProductoEnVentaArchivo(Producto producto){
	
	ofstream registrosCuentas;
	
	string rutaDatosProductosEnVenta = "../Cuentas/" + usuario + "/datos_productos_venta.csv";
	
	registrosCuentas.open(rutaDatosProductosEnVenta, ios::app);
	
	registrosCuentas << producto.getID() << endl;
	
	registrosCuentas.close();
}

void Cuenta::editarClave(string nuevoDato){
	
	clave = nuevoDato;
	
	string rutaDatosUsuario = "../Cuentas/" + usuario + "/datos_cuenta.csv";
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosUsuario, ios::out);
	
	registrosCuentas << "Nombre;Correo;Celular;Usuario;Clave";
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave;
	
}

void Cuenta::editarCorreo(string nuevoDato){
	
	correo = nuevoDato;
	
	string rutaDatosUsuario = "../Cuentas/" + usuario + "/datos_cuenta.csv";
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosUsuario, ios::out);
	
	registrosCuentas << "Nombre;Correo;Celular;Usuario;Clave";
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave;
	
}

void Cuenta::editarCelular(string nuevoDato){
	
	celular = nuevoDato;
	
	string rutaDatosUsuario = "../Cuentas/" + usuario + "/datos_cuenta.csv";
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosUsuario, ios::out);
	
	registrosCuentas << "Nombre;Correo;Celular;Usuario;Clave";
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave;
	
}

void Cuenta::editarNombre(string nuevoDato){
	
	nombre = nuevoDato;
	
	string rutaDatosUsuario = "../Cuentas/" + usuario + "/datos_cuenta.csv";
	
	ofstream registrosCuentas;
	
	registrosCuentas.open(rutaDatosUsuario, ios::out);
	
	registrosCuentas << "Nombre;Correo;Celular;Usuario;Clave";
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave;
	
}

void Cuenta::agregarProductoEnVenta(Producto producto){
	
	productosEnVenta.push_back(producto);
	
}

vector<Producto> Cuenta::getProductosEnVenta(){
	
	return productosEnVenta;
	
}

vector<Direccion> Cuenta::getDireccion(){
	
	return direcciones;
}

vector<Compra> Cuenta::getProductosComprados(){
	
	return productosComprados;
	
}

vector<Producto> Cuenta::getCarritoCompras(){
	
	return carritoCompras;
	
}

string Cuenta::getUsuario(){
	
	return usuario;
}

string Cuenta::getClave(){
	
	return clave;
}


vector<Tarjeta> Cuenta::getTarjetas(){
	
	return tarjetas;
}



