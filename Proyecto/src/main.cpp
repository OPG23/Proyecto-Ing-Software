#include <iostream>

#include "../include/menus.h"

using namespace std;

void agregarCuentasDelArchivo(vector<Cuenta> &cuentas);

int main(){
	
	setlocale(LC_ALL, "SPANISH");
	
	vector<Cuenta> cuentas;
	
	vector<Producto> productos;
	
	agregarCuentasDelArchivo(cuentas);

	if(cuentas.size() > 1){
		
		ordenarCuentas(cuentas, 0, cuentas.size() - 1);
	}
	
    menuPrincipal(cuentas, productos);
    
    return 0;
}

void agregarCuentasDelArchivo(vector<Cuenta> &cuentas){
	
	fstream registrosCuentas("../Cuentas/registros_cuentas.csv");
	
	ifstream registrosCuentasComprobar("../Cuentas/registros_cuentas.csv");
	
	if(!registrosCuentasComprobar.is_open()){
		
		ofstream crearRegistrosCuentas("../Cuentas/registros_cuentas.csv");
		
		crearRegistrosCuentas << "Nombre" << ";" << "Correo" << ";" << "Celular" << ";" << "Usuario" << ";" << "Clave" << ";" << "Numero Tarjeta" << ";" << "CVV de Tarjeta" << ";" << "Fecha De Vencimiento"  << ";" << "Nombre De Tarjeta";
	
		crearRegistrosCuentas.close();
	}else{
		string linea;
		
		getline(registrosCuentas, linea);
		
		while(getline(registrosCuentas, linea)){
			
			string nombre, correo, celular, usuario, clave, numeroTarjeta, cvvTarjeta, fechaVencimiento, nombreTitularTarjeta;
			
			stringstream Linea (linea);
			
			getline(Linea, nombre, ';');
			
			getline(Linea, correo, ';');
			
			getline(Linea, celular, ';');
			
			getline(Linea, usuario, ';');
			
			getline(Linea, clave, ';');
			
			getline(Linea, numeroTarjeta, ';');
			
			getline(Linea, cvvTarjeta, ';');
			
			getline(Linea, fechaVencimiento, ';');
			
			getline(Linea, nombreTitularTarjeta, ';');
			
			Cuenta cuenta;
			
			cuenta.agregarDatos(usuario, clave, nombre, correo, celular, numeroTarjeta, cvvTarjeta, fechaVencimiento, nombreTitularTarjeta);
			
			cuentas.push_back(cuenta);
		}
	}
	
	registrosCuentasComprobar.close();
	
	registrosCuentas.close();
}


