#include <iostream>

#include "tarjetas.h"

#include <fstream>

#include <sstream>

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
		
		bool agregarDatosPorConsola();
		
		void agregarDatos(string _usuario, string _clave, string _nombre, string _correo, string _celular, string numeroTarjeta, string cvvTarjeta, string fechaVencimiento, string nombreTitularTarjeta);
		
		void guardarCuentaEnArchivo();
		
		bool correoValido(string _correo);
		
		bool celularValido(string _celular);
		
		bool nombreValido(string _nombre);
		
		void imprimirCuenta();
		
		string getUsuario();
		
		string getClave();
};

Cuenta::Cuenta(){
}

bool Cuenta::agregarDatosPorConsola(){
	
	string _usuario = "";
		
	string _clave = "";
		
	string _nombre = "";
		
	string _correo = "";
		
	string _celular = "";
		
	textoNormal("Ingrese el correo electronico: ", false);
	
	cin >> _correo;
	
	if(correoValido(_correo)){
		
		textoNormal("Ingrese su numero de celular: ", false);
		
		cin >> _celular;
		
		if(celularValido(_celular)){
			
			textoNormal("Ingrese su nombre completo: ", false);
			
			cin.ignore();
			
			getline(cin, _nombre);
			
			if(nombreValido(_nombre)){
				
				textoNormal("Ingrese su nombre de usuario: ", false);
				
				getline(cin, _usuario);
				
				if(_usuario != ""){
					
					textoNormal("Ingrese su contraseña: ", false);
					
					cin >> _clave;
					
					if(_clave != ""){
						
						bool agregarTarjeta;
						
						correo = _correo;
						
						celular = _celular;
						
						nombre = _nombre;
						
						usuario = _usuario;
						
						clave = _clave;
						
						cout << endl;
						
						textoNormal("¿Desea agregar una tarjeta de credito ahora?", true);
						
						textoNormal("Ingrese 0 para no y 1 para sí: ", false);
						
						cin >> agregarTarjeta;
						
						if(agregarTarjeta){
							
							Tarjeta _tarjeta;
							
							_tarjeta.agregarTarjetaPorConsola();
							
							tarjeta = _tarjeta;
							
						}
						
						guardarCuentaEnArchivo();
						
						return true;
						
					}else{
						
						textoNormal("Agrege una contraseña valida.", true);
					}
					
				}else{
					
					textoNormal("Ingrese un nombre de usuario valido.", true);
					
				}
			}else{
				
				textoNormal("Ingrese un nombre valido", true);
			}
		}else{
			
			textoNormal("Celular no valido.", true);
		}
		
	}else{
		
		textoNormal("Correo no valido.", true);
	}
	
	return false;
	
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
	
	registrosCuentas.open("Cuentas/registros_cuentas.csv", std::ios::app);
	
	registrosCuentas << endl << nombre << ";" << correo << ";" << celular << ";" << usuario << ";" << clave << ";" << tarjeta.getNumeroTarjeta() << ";" << tarjeta.getCvvTarjeta() << ";" << tarjeta.getFechaVencimientoTarjeta() << ";" << tarjeta.getNombreTarjeta();
	
	registrosCuentas.close();
	
}

bool Cuenta::correoValido(string _correo){
	
	regex regex("^(.+)@(\\S+)$");
	
	return regex_match(_correo, regex);
}

bool Cuenta::celularValido(string _celular){
	
	regex regex("^3[0-9]{9}$");
	
	return regex_match(_celular, regex);
}

bool Cuenta::nombreValido(string _nombre){
	
	regex regex("^[A-Za-z ]+$");
	
	return regex_match(_nombre, regex);
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



