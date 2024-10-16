#include <iostream>

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
		
		void agregarTarjeta(string _numeroTarjeta, string _cvvTarjeta, string _fechaVencimientoTarjeta, string _nombreTarjeta);
		
		string getNumeroTarjeta();
		
		string getCvvTarjeta();
		
		string getFechaVencimientoTarjeta();
		
		string getNombreTarjeta();
};

Tarjeta::Tarjeta(){
}

void Tarjeta::agregarTarjeta(string _numeroTarjeta, string _cvvTarjeta, string _fechaVencimientoTarjeta, string _nombreTarjeta){
	
	numeroTarjeta = _numeroTarjeta;
	
	cvvTarjeta = _cvvTarjeta;
	
	fechaVencimientoTarjeta = _fechaVencimientoTarjeta;
	
	nombreTarjeta = _nombreTarjeta;
	
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









