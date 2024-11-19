#include <iostream>

using namespace std;

class Direccion{
	
	protected:
		
		string direccionCompleta;
		
		string datosAdicionales;
		
		string puntosDeReferencia;
		
	public:
		
		void agregarDatosDireccion(string _direccionCompleta, string _datosAdicionales, string _puntosDeReferencia);
		
		string getDireccionCompleta();
		
		string getDatosAdicionales();
		
		string getPuntosDeReferencia();
};

void Direccion::agregarDatosDireccion(string _direccionCompleta, string _datosAdicionales, string _puntosDeReferencia){
	
	direccionCompleta = _direccionCompleta;
	
	datosAdicionales = _datosAdicionales;
	
	puntosDeReferencia = _puntosDeReferencia;
	
}

string Direccion::getDatosAdicionales(){
	
	return datosAdicionales;
	
}

string Direccion::getDireccionCompleta(){
	
	return direccionCompleta;
	
}

string Direccion::getPuntosDeReferencia(){
	
	return puntosDeReferencia;
	
}
