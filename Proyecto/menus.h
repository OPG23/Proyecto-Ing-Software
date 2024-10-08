#include <iostream>

#include <windows.h>

#include "ordenarYBuscar.h"

using namespace std;

void menuPrincipal(vector<Cuenta> &cuentas){
	
	int op;
	
	do{
		
		system("cls");
	
		textoAscii("Market UAN");
		
		textoNormal("------------------Men�------------------", true);
		
		textoNormal("0. Salir.", true);
		
		textoNormal("1. Registrarse.", true);
		
		textoNormal("2. Iniciar Sesi�n.", true);
		
		textoNormal("Ingrese una opci�n: ", false);
		
		cin >> op;
		
		switch(op){
			
			case 0:{
				
				textoNormal("Adios", true);
				
				break;
			}
			
			case 1:{
				
				Cuenta cuenta;
				
				bool cuentaCreada = cuenta.agregarDatosPorConsola();
				
				int posicion = busquedaPosicionCuenta(cuentas, cuenta.getUsuario());
				
				if(posicion == -1){
				 	
					textoNormal("El usuario ya est� en uso", true);
					
					system("PAUSE");
				}else{
					
					if(cuentaCreada){
						
					textoNormal("Cuenta creada con exito.", true);
					
					cuentas.insert(cuentas.begin() + posicion, cuenta);
					
					}
					
					system("PAUSE");
				}
				
				break;
			}
			
			case 2:{
				
				string usuario, clave;
				
				textoNormal("Ingrese su usuario: ", false);
				
				cin >> usuario;
				
				textoNormal("Ingrese su clave: ", false);
				
				cin >> clave;
				
				if(busquedaCuentaLogin(cuentas, usuario, clave)){
					
					string texto = "Bienvenido ";
					
					texto += usuario;
					
					textoNormal(texto, true);
					
					system("PAUSE");
				}else{
					
					textoNormal("Usuario o contrase�a no valida.", true);
					
					system("PAUSE");
				}
				
				break;
			}
			
			default:{
				
				textoNormal("Opci�n no valida", true);
				
				system("PAUSE");
				
				break;
			}
		}
	}while(op != 0);
	
	
}











