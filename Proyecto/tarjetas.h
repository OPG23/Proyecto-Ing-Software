#include <iostream>

#include "escribirEnPantalla.h"

#include <fstream>

#include <sstream>

#include <regex>

using namespace std;

class Tarjeta{
	
	protected:
		
		string numeroTarjeta;
		
		string cvvTarjeta;
		
		string fechaVencimientoTarjeta;
		
		string nombreTarjeta;
	
	public:
		
		Tarjeta();
		
		void agregarTarjetaPorConsola();
		
		void agregarTarjeta(string _numeroTarjeta, string _cvvTarjeta, string _fechaVencimientoTarjeta, string _nombreTarjeta);
		
		bool numeroTarjetaValida(string _numeroTarjeta);
		
		bool cvvTarjetaValida(string _cvvTarjeta);
		
		bool fechaVencimientoTarjetaValida(string _fechaVencimientoTarjeta);
		
		string getNumeroTarjeta();
		
		string getCvvTarjeta();
		
		string getFechaVencimientoTarjeta();
		
		string getNombreTarjeta();
};

Tarjeta::Tarjeta(){
}

void Tarjeta::agregarTarjetaPorConsola(){
	
	string _numeroTarjeta;
		
	string _cvvTarjeta;
		
	string _fechaVencimientoTarjeta;
		
	string _nombreTarjeta;
	
	textoNormal("Ingrese el numero de la tarjeta: ", false);
	
	cin >> _numeroTarjeta;
	
	if(numeroTarjetaValida(_numeroTarjeta)){
		
		
		textoNormal("Ingrese el cvv de la tarjeta: ", false);
		
		cin >> _cvvTarjeta;
		
		if(cvvTarjetaValida(_cvvTarjeta)){
			
		
			textoNormal("Ingrese la fecha de vencimiento de la tarjeta en formato (mes/año), ejemplo (12/2029): ", false);
			
			cin >> _fechaVencimientoTarjeta;
			
			if(fechaVencimientoTarjetaValida(_fechaVencimientoTarjeta)){
				
				textoNormal("Ingrese el nombre del titular de la tarjeta: ", false);
				
				cin.ignore();
				
				getline(cin, _nombreTarjeta) ;
				
				cvvTarjeta = _cvvTarjeta;
				
				numeroTarjeta = _numeroTarjeta;
				
				nombreTarjeta = _nombreTarjeta;
				
				fechaVencimientoTarjeta = _fechaVencimientoTarjeta;
				
				textoNormal("Tarjeta agregada con exito.", true);
				
			}else{
				
				textoNormal("Fecha de vencimiento no valida.", true);
			}
			
		}else{
			
			textoNormal("cvv no valido.", true);	
		}
		
	}else{
		
		textoNormal("Numero de tarjeta no valido.", true);
	}
}

void Tarjeta::agregarTarjeta(string _numeroTarjeta, string _cvvTarjeta, string _fechaVencimientoTarjeta, string _nombreTarjeta){
	
	numeroTarjeta = _numeroTarjeta;
	
	cvvTarjeta = _cvvTarjeta;
	
	fechaVencimientoTarjeta = _fechaVencimientoTarjeta;
	
	nombreTarjeta = _nombreTarjeta;
	
}

bool Tarjeta::numeroTarjetaValida(string _numeroTarjeta){
	
	regex regex("^(?:(4[0-9]{12}(?:[0-9]{3})?)|(5[1-5][0-9]{14})|(6(?:011|5[0-9]{2})[0-9]{12})|(3[47][0-9]{13})|(3(?:0[0-5]|[68][0-9])[0-9]{11})|((?:2131|1800|35[0-9]{3})[0-9]{11}))$");
	
	return regex_match(_numeroTarjeta, regex);
}

bool Tarjeta::cvvTarjetaValida(string _cvvTarjeta){
	
	regex regex("^[0-9]{3}$");
	
	return regex_match(_cvvTarjeta, regex);
}

bool Tarjeta::fechaVencimientoTarjetaValida(string _fechaVencimientoTarjeta){
	
	regex regex("^(0[1-9]|1[0-2])/20(2[5-9]|[3-9][0-9])$");
	
	return regex_match(_fechaVencimientoTarjeta, regex);
}

string Tarjeta::getNumeroTarjeta(){
	
	return numeroTarjeta;
}

string Tarjeta::getCvvTarjeta(){
	
	return cvvTarjeta;
}

string Tarjeta::getFechaVencimientoTarjeta(){
	
	return fechaVencimientoTarjeta;
}

string Tarjeta::getNombreTarjeta(){
	
	return nombreTarjeta;
}









