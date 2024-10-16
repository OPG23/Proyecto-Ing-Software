#include <iostream>

#include <windows.h>

#include "ordenarYBuscar.h"

using namespace std;

void menuPrincipal(vector<Cuenta> &cuentas, vector <Producto> &productos);

void menuPrincipal_Registro(vector<Cuenta> &cuentas, int anchoVentana, Cuenta &cuenta);

bool correoValido(string _correo);

bool celularValido(string _celular);

bool nombreValido(string _nombre);

bool usuarioValido(string _usuario, vector<Cuenta> &cuentas);

bool claveValida(string _clave);

Tarjeta agregarTarjetaPorConsola(int ancho);

bool numeroTarjetaValida(string _numeroTarjeta);

bool cvvTarjetaValida(string _cvvTarjeta);

bool fechaVencimientoTarjetaValida(string _fechaVencimientoTarjeta);

void menuSesionIniciada(Cuenta &cuenta, vector <Producto> &productos);

void menuSesionIniciada_AgregarProducto(string usuario, int ancho);



void menuPrincipal(vector<Cuenta> &cuentas, vector <Producto> &productos){
	
	int op;
	
	do{
		
		system("cls");
		
		int ancho = anchoVentana();
	
		textoAscii("Market UAN", ancho);
		
		textoNormal("------------------Menú------------------", ancho, true);
		
		textoNormal("0. Salir.", ancho, true);
		
		textoNormal("1. Registrarse.", ancho, true);
		
		textoNormal("2. Iniciar Sesión.", ancho, true);
		
		textoNormal("Ingrese una opción: ", ancho, false);
		
		cin >> op;
		
		switch(op){
			
			case 0:{
				
				textoNormal("Adios", ancho, true);
				
				break;
			}
			
			case 1:{
				
				Cuenta cuenta;
				
				menuPrincipal_Registro(cuentas, ancho, cuenta);
				
				menuSesionIniciada(cuenta, productos);
				
				break;
			}
			
			case 2:{
				
				string usuario, clave;
				
				Cuenta cuenta;
				
				textoNormal("Ingrese su usuario: ", ancho, false);
				
				cin >> usuario;
				
				textoNormal("Ingrese su clave: ", ancho, false);
				
				cin >> clave;
				
				if(busquedaCuentaLogin(cuentas, usuario, clave, cuenta)){
					
					menuSesionIniciada(cuenta, productos);
					
					system("PAUSE");
				}else{
					
					textoNormal("Usuario o contraseña no valida.", ancho, true);
					
					system("PAUSE");
				}
				
				break;
			}
			
			default:{
				
				textoNormal("Opción no valida", ancho, true);
				
				system("PAUSE");
				
				break;
			}
		}
	}while(op != 0);
	
	
}

void menuPrincipal_Registro(vector<Cuenta> &cuentas, int ancho, Cuenta &cuenta){
	
	string _usuario = "";
		
	string _clave = "";
		
	string _nombre = "";
		
	string _correo = "";
		
	string _celular = "";
	
	bool datoCorrecto = false;
		
	while(!datoCorrecto){
		
		textoNormal("Ingrese el correo electronico: ", ancho, false);
	
		cin >> _correo;
	
		datoCorrecto = correoValido(_correo);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese un correo valido", ancho, true);
		}
	}
	
	datoCorrecto = false;
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese su numero de celular: ", ancho, false);
	
		cin >> _celular;
	
		datoCorrecto = celularValido(_celular);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese un celular valido", ancho, true);
		}
	}
	
	cin.ignore();
	
	datoCorrecto = false;
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese su nombre completo: ", ancho, false);
	
		getline(cin, _nombre);
	
		datoCorrecto = nombreValido(_nombre);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese un nombre valido", ancho, true);
		}
	}
	
	datoCorrecto = false;
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese su nombre de usuario: ", ancho, false);
	
		cin >> _usuario;
	
		datoCorrecto = usuarioValido(_usuario, cuentas);
		
		if(!datoCorrecto){
			
			textoNormal("Usuario en uso, ingrese uno diferente", ancho, true);
		}
	}
	
	datoCorrecto = false;
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese su contraseña: ", ancho, false);
	
		cin >> _clave;
	
		datoCorrecto = claveValida(_clave);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese una contraseña valido", ancho, true);
		}
	}
	
	Cuenta cuentaRegistrar;
	
	bool agregarTarjeta;
						
	cout << endl;
						
	textoNormal("¿Desea agregar una tarjeta de credito ahora?", ancho, true);
						
	textoNormal("Ingrese 0 para no y 1 para sí: ", ancho, false);
						
	cin >> agregarTarjeta;
						
	if(agregarTarjeta){
							
		Tarjeta _tarjeta;
							
		_tarjeta = agregarTarjetaPorConsola(ancho);
							
		cuentaRegistrar.agregarDatos(_usuario, _clave, _nombre, _correo, _celular, _tarjeta.getNumeroTarjeta(), _tarjeta.getCvvTarjeta(), _tarjeta.getFechaVencimientoTarjeta(), _tarjeta.getNombreTarjeta());
							
	}else{
		
		cuentaRegistrar.agregarDatos(_usuario, _clave, _nombre, _correo, _celular, "", "", "", "");
	}
	
	cuentaRegistrar.guardarCuentaEnArchivo();
	
	int posicion = busquedaPosicionCuenta(cuentas, _usuario);
	
	cuentas.insert(cuentas.begin() + posicion, cuentaRegistrar);
	
	cuenta = cuentaRegistrar;
	
	textoNormal("Cuenta creada con exito.", ancho, true);
	
	system("PAUSE");
	
}

bool correoValido(string _correo){
	
	regex regex("^(.+)@(\\S+)$");
	
	return regex_match(_correo, regex);
}

bool celularValido(string _celular){
	
	regex regex("^3[0-9]{9}$");
	
	return regex_match(_celular, regex);
}

bool nombreValido(string _nombre){
	
	regex regex("^[A-Za-z ]+$");
	
	return regex_match(_nombre, regex);
}

bool usuarioValido(string _usuario, vector<Cuenta> &cuentas){
	
	int posicion = busquedaPosicionCuenta(cuentas, _usuario);
	
	if(posicion == -1){
		
		return false;
		
	}else{
		
		return true;
		
	}
	
}

bool claveValida(string _clave){

	if(_clave != ""){
		
		return true;
		
	}else{
		
		return false;
		
	}
}

Tarjeta agregarTarjetaPorConsola(int ancho){
	
	string _numeroTarjeta;
		
	string _cvvTarjeta;
		
	string _fechaVencimientoTarjeta;
		
	string _nombreTarjeta;
	
	bool datoCorrecto = false;
		
	while(!datoCorrecto){
		
		textoNormal("Ingrese el numero de la tarjeta: ", ancho, false);
	
		cin >> _numeroTarjeta;
	
		datoCorrecto = numeroTarjetaValida(_numeroTarjeta);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese un numero de tarjeta valido", ancho, true);
		}
	}
	
	datoCorrecto = false;
	
	cin.ignore();
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese el cvv de la tarjeta: ", ancho, false);
	
		cin >> _cvvTarjeta;
	
		datoCorrecto = cvvTarjetaValida(_cvvTarjeta);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese un cvv de tarjeta valido", ancho, true);
		}
	}
	
	datoCorrecto = false;
	
	cin.ignore();
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese la fecha de vencimiento de la tarjeta en formato (mes/año), ejemplo (12/2029): ", ancho, false);
	
		cin >> _fechaVencimientoTarjeta;
	
		datoCorrecto = fechaVencimientoTarjetaValida(_fechaVencimientoTarjeta);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese una fecha de vencimiento de tarjeta valido", ancho, true);
		}
	}
	
	datoCorrecto = false;
	
	cin.ignore();
	
	while(!datoCorrecto){
		
		textoNormal("Ingrese el nombre del titular de la tarjeta: ", ancho, false);
	
		getline(cin, _nombreTarjeta);
	
		datoCorrecto = nombreValido(_nombreTarjeta);
		
		if(!datoCorrecto){
			
			textoNormal("Ingrese un nombre valido", ancho, true);
		}
	}
	
	Tarjeta tarjeta;
	
	tarjeta.agregarTarjeta(_numeroTarjeta, _cvvTarjeta, _fechaVencimientoTarjeta, _nombreTarjeta);
	
	textoNormal("Tarjeta agregada con exito.", ancho, true);
			
	return tarjeta;
}

bool numeroTarjetaValida(string _numeroTarjeta){
	
	regex regex("^(?:(4[0-9]{12}(?:[0-9]{3})?)|(5[1-5][0-9]{14})|(6(?:011|5[0-9]{2})[0-9]{12})|(3[47][0-9]{13})|(3(?:0[0-5]|[68][0-9])[0-9]{11})|((?:2131|1800|35[0-9]{3})[0-9]{11}))$");
	
	return regex_match(_numeroTarjeta, regex);
}

bool cvvTarjetaValida(string _cvvTarjeta){
	
	regex regex("^[0-9]{3}$");
	
	return regex_match(_cvvTarjeta, regex);
}

bool fechaVencimientoTarjetaValida(string _fechaVencimientoTarjeta){
	
	regex regex("^(0[1-9]|1[0-2])/20(2[5-9]|[3-9][0-9])$");
	
	return regex_match(_fechaVencimientoTarjeta, regex);
}

void menuSesionIniciada(Cuenta &cuenta, vector <Producto> &productos){
	
	int op;
	
	do{
		
		system("cls");
		
		int ancho = anchoVentana();
		
		string textoBienvenida = "Bienvenido " + cuenta.getUsuario();
	
		textoAscii("Market UAN", ancho);
		
		textoNormal(textoBienvenida, ancho, true);
		
		textoNormal("------------------Menú------------------", ancho, true);
		
		textoNormal("0. Cerrar sesion.", ancho, true);
		
		textoNormal("1. Buscar un producto o un servicio.", ancho, true);
		
		textoNormal("2. Mostrar el catalogo completo.", ancho, true);
		
		textoNormal("3. Ver mi carrito.", ancho, true);
		
		textoNormal("4. Ver mis mensajes.", ancho, true);
		
		textoNormal("5. Ver mis compras.", ancho, true);
		
		textoNormal("6. Vender un producto.", ancho, true);
		
		textoNormal("7. Editar un producto.", ancho, true);
		
		textoNormal("8. Ofrecer un servicio.", ancho, true);
		
		textoNormal("9. Editar un servicio.", ancho, true);
		
		textoNormal("10. Configuración de la cuenta", ancho, true);
		
		textoNormal("11. PQR.", ancho, true);
		
		textoNormal("Ingrese una opción: ", ancho, false);
		
		cin >> op;
		
		switch(op){
			
			case 0:{
				
				textoNormal("Adios", ancho, true);
				
				break;
			}
			
			case 6:{
				
				menuSesionIniciada_AgregarProducto(cuenta.getUsuario(), ancho);
				
				break;
			}
			
			
			default:{
				
				textoNormal("Opción no valida", ancho, true);
				
				system("PAUSE");
				
				break;
			}
		}
	}while(op != 0);
	
}

void menuSesionIniciada_AgregarProducto(string usuario, int ancho){
	
	string nombre;
	
	string descripcion;
	
	string precio;
	
	int stock;
	
	bool precioValido = false;
	
	cin.ignore();
	
	textoNormal("Ingrese el nombre del producto: ", ancho, false);
	
	getline(cin, nombre);
	
	textoNormal("Ingrese la descripcion del producto: ", ancho, false);
	
	getline(cin, descripcion);
	
	while(!precioValido){
		
		textoNormal("Ingrese el precio del producto: ", ancho, false);
		
		cin >> precio;
		
		regex expresionRegularPrecioValido("^[0-9]+$");

		precioValido = regex_match(precio, expresionRegularPrecioValido);
		
		if(!precioValido){
			
			textoNormal("Ingrese un precio valido.", ancho, true);
		}
	}
	
	cin.ignore();
	
	textoNormal("Ingrese el stock del producto: ", ancho, false);
	
	cin >> stock;
	
	Producto producto;
	
	producto.agregarProducto(nombre, descripcion, precio, stock, usuario);
}


