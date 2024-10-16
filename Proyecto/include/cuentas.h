#include <iostream>

#include "tarjetas.h"

#include <fstream>

using namespace std;

class Cuenta{
	
	protected:
		
		string usuario;
		
		string clave;
		
		string nombre;
		
		string correo;
		
		string celular;
		
		Tarjeta tarjeta;
	
	public:
		
		Cuenta();
		
		void agregarDatos(string _usuario, string _clave, string _nombre, string _correo, string _celular, string numeroTarjeta, string cvvTarjeta, string fechaVencimiento, string nombreTitularTarjeta);
		
		void guardarCuentaEnArchivo();
		
		void imprimirCuenta();
		
		string getUsuario();
		
		string getClave();
};

Cuenta::Cuenta(){
}


void Cuenta::agregarDatos(string _usuario, string _clave, string _nombre, string _correo, string _celular, string numeroTarjeta, string cvvTarjeta, string fechaVencimiento, string nombreTitularTarjeta){
	
	usuario = _usuario;
		
	clave = _clave;
		
	nombre = _nombre;
		
	correo = _correo;
		
	celular = _celular;
	
	if(numeroTarjeta != ""){
		
		Tarjeta _tarjeta;
		
		_tarjeta.agregarTarjeta(numeroTarjeta, cvvTarjeta, fechaVencimiento, nombreTitularTarjeta);
		
		tarjeta = _tarjeta;
	}
	
}

void Cuenta::guardarCuentaEnArchivo(){
	
	ofstream registrosCuentas;
	
	registrosCuentas.open("../Cuentas/registros_cuentas.csv", ios::app);
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave << ";" << tarjeta.getNumeroTarjeta() << ";" << tarjeta.getCvvTarjeta() << ";" << tarjeta.getFechaVencimientoTarjeta() << ";" << tarjeta.getNombreTarjeta();
	
	registrosCuentas.close();
	
}

void Cuenta::imprimirCuenta(){
	
	cout << usuario << " " << clave << " " << nombre << " " << correo << " " << celular << endl;
	
}

string Cuenta::getUsuario(){
	
	return usuario;
}

string Cuenta::getClave(){
	
	return clave;
}



