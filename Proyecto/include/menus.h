#include <iostream>

#include <windows.h>

#include <iomanip>

#include "ordenarYBuscar.h"

#include <ctime>

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

void menuSesionIniciada(Cuenta &cuenta, vector <Producto> &productos, vector<Cuenta> &cuentas);

void menuSesionIniciada_BuscarProductoServicio(vector <Producto> &productos, Cuenta &cuenta, int ancho);

void menuSesionIniciada_MostrarTodosLosProductos(vector <Producto> &productos, int ancho, Cuenta &cuenta);

void menuSesionIniciada_VerCarrito(int ancho, Cuenta &cuenta);

void menuSesionIniciada_AgregarProducto(vector <Producto> &productos, Cuenta &cuenta, int ancho);

bool menuSesionIniciada_AgregarProducto_IDExiste(vector <Producto> productos, int id);

void menuSesionIniciada_AgregarDireccion(Cuenta &cuenta, int ancho);

void menuSesionIniciada_Finalizar(Direccion direccionDeCompra, vector<Producto> productosComprados, Cuenta &cuenta, string medioDePago, int ancho);

void menuSesionIniciada_Comprar(Cuenta &cuenta, int ancho, vector<Producto> productosComprados, string medioDePago);

void menuSesionIniciada_ActualizarRegistrosCarrito(Cuenta &cuenta);

void menuSesionIniciada_Comprar_PagoTarjeta(Cuenta &cuenta, int ancho, vector<Producto> productosComprar);

void menuSesionIniciada_MetodosDePago(Cuenta &cuenta, int ancho, vector<Producto> productosComprar);

void menuSesionIniciada_MostrarCompras(int ancho, vector<Compra> productosComprados);

void menuSesionIniciada_EditarProducto(vector <Producto> &productos, Cuenta &cuenta, int ancho);

void menuSesionIniciada_ConfiguracionCuenta(int ancho, vector<Cuenta> &cuentas, Cuenta &cuenta);

void menuSesionIniciada_ConfiguracionCuenta_EditarCuenta(int ancho, Cuenta &cuenta);




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
				
				menuSesionIniciada(cuenta, productos, cuentas);
				
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
					
					menuSesionIniciada(cuenta, productos, cuentas);
					
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
	
	int agregarTarjeta;
						
	cout << endl;
						
	textoNormal("¿Desea agregar una tarjeta de credito ahora?", ancho, true);
						
	textoNormal("Ingrese 0 para no y 1 para sí: ", ancho, false);
						
	cin >> agregarTarjeta;
	
	switch(agregarTarjeta){
		
		case 0:{
			
			cuentaRegistrar.agregarDatos(_usuario, _clave, _nombre, _correo, _celular);
			
			break;
		}
		
		case 1:{
				
			Tarjeta _tarjeta;
								
			_tarjeta = agregarTarjetaPorConsola(ancho);
								
			cuentaRegistrar.agregarDatos(_usuario, _clave, _nombre, _correo, _celular);
			
			cuentaRegistrar.setTarjeta(_tarjeta);
			
			cuentaRegistrar.guardarTarjetaArchivo(_tarjeta);
			
			break;
		}
		
		default:{
			
			textoNormal("Opción no valida, agregue la tarjeta despues.", ancho, true);
			
			break;
		}
	}
	
	cuentaRegistrar.guardarCuentaEnArchivo();
	
	int posicionInsertar;
	
	int posicion = busquedaPosicionCuenta(cuentas, _usuario, posicionInsertar);
	
	cuentas.insert(cuentas.begin() + posicionInsertar, cuentaRegistrar);
	
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
	
	int variableNoUsable;
	
	int posicion = busquedaPosicionCuenta(cuentas, _usuario, variableNoUsable);
	
	if(posicion != -1){
		
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

void menuSesionIniciada(Cuenta &cuenta, vector<Producto> &productos, vector<Cuenta> &cuentas){
	
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
		
		textoNormal("4. Ver mis compras.", ancho, true);
		
		textoNormal("5. Vender un producto o servicio.", ancho, true);
		
		textoNormal("6. Editar un producto o servicio.", ancho, true);
		
		textoNormal("7. Configuración de la cuenta", ancho, true);
		
		textoNormal("Ingrese una opción: ", ancho, false);
		
		cin >> op;
		
		switch(op){
			
			case 0:{
				
				textoNormal("Adios", ancho, true);
				
				break;
			}
			
			case 1:{
				
				if(cuentas.size() > 0){
					
					menuSesionIniciada_BuscarProductoServicio(productos, cuenta, ancho);
					
				}else{
					
					textoNormal("No hay productos agregados.", ancho, true);
					
				}
				
				break;
			}
			
			case 2:{
				
				if(cuentas.size() > 0){
					
					menuSesionIniciada_MostrarTodosLosProductos(productos, ancho, cuenta);	
					
				}else{
					
					textoNormal("No hay productos agregados.", ancho, true);
					
				}
				
				break;
			}
			
			case 3:{
				
				menuSesionIniciada_VerCarrito(ancho, cuenta);
				
				break;
			}
			
			case 4:{
				
				menuSesionIniciada_MostrarCompras(ancho, cuenta.getProductosComprados());
				
				
				break;
			}
			
			case 5:{
				
				menuSesionIniciada_AgregarProducto(productos, cuenta, ancho);
				
				break;
			}
			
			case 6:{
				
				menuSesionIniciada_EditarProducto(productos, cuenta, ancho);
				
				break;
			}
			
			case 7:{
				
				menuSesionIniciada_ConfiguracionCuenta(ancho, cuentas, cuenta);
				
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

void menuSesionIniciada_BuscarProductoServicio(vector <Producto> &productos, Cuenta &cuenta, int ancho){
	
	string nombreProductoBuscar;
	
	cin.ignore();
	
	textoNormal("Ingrese el nombre del procuto: ", ancho, false);
	
	getline(cin, nombreProductoBuscar);
	
	Producto producto;
	
	producto = busquedaPosicionProducto(productos, nombreProductoBuscar, ancho);
	
	if(producto.getNombre() == "noAgregarProducto15478896587549852456586465132165489"){
		
		system("pause");
	}else{
		
		cuenta.agregarProductoCarrito(producto);
			
		textoNormal("Producto agregado con exito.", ancho, true);
		
		ofstream guardarEnArchivo;
			
		string ruta = "../Cuentas/" + cuenta.getUsuario() + "/datos_carrito.csv";
	
		guardarEnArchivo.open(ruta, ios::app);
			
		guardarEnArchivo << producto.getID() << endl;
			
		guardarEnArchivo.close();
			
		system("pause");
	}
}

void menuSesionIniciada_MostrarTodosLosProductos(vector <Producto> &productos, int ancho, Cuenta &cuenta){
	
	int op;
	
	int idProductoCompra;
	
	textoNormal("Seleccione como desea verlos.", ancho, true);
	
	textoNormal("1. Por precio de mayor a menor.", ancho, true);
	
	textoNormal("2. Por precio de menor a mayor", ancho, true);
	
	textoNormal("3. Sin filtro", ancho, true);
	
	textoNormal("Ingrese la opción: ", ancho, false);
	
	cin >> op;
	
	cin.ignore();
	
	switch (op){
		
		case 1:{
			
			if(productos.size() > 1){
			
				ordenarProductosPorPrecioMayor(productos, 0, productos.size() - 1);
			}
				
			for(int i = 0; i < productos.size(); i++){
				
				string mensaje = to_string(i + 1) + ". Nombre: " + productos[i].getNombre() + ", Descripción: " + productos[i].getDescripcion() + ", Precio: " + productos[i].getPrecio() + ", Stock: " + to_string(productos[i].getStock()) + ".";
					
				textoNormal(mensaje, ancho, true);
					
			}
				
			break;
		}
		
		case 2:{
			
			if(productos.size() > 1){
			
				ordenarProductosPorPrecioMenor(productos, 0, productos.size() - 1);
			}
				
			for(int i = 0; i < productos.size(); i++){
					
				string mensaje = to_string(i + 1) + ". Nombre: " + productos[i].getNombre() + ", Descripción: " + productos[i].getDescripcion() + ", Precio: " + productos[i].getPrecio() + ", Stock: " + to_string(productos[i].getStock()) + ".";
						
				textoNormal(mensaje, ancho, true);
					
			}
			
			break;
		}
		
		default:{
			
			for(int i = 0; i < productos.size(); i++){
				
				string mensaje = to_string(i + 1) + ". Nombre: " + productos[i].getNombre() + ", Descripción: " + productos[i].getDescripcion() + ", Precio: " + productos[i].getPrecio() + ", Stock: " + to_string(productos[i].getStock()) + ".";
						
				textoNormal(mensaje, ancho, true);
					
			}
			
			break;
		}
	}
	
	textoNormal("Ingrese el numero del producto que desea agregar, 0 si no desea agregar ninguno: ", ancho, false);
	
	cin >> idProductoCompra;
	
	if(idProductoCompra > 0 && idProductoCompra < productos.size() + 1){
		
		cuenta.agregarProductoCarrito(productos[idProductoCompra - 1]);
		
		textoNormal("Producto agregado correctamente.", ancho, true);
		
	}else if(idProductoCompra == 0){
		
		textoNormal("Regresando al menú anterior.", ancho, true);
		
	}else{
		
		textoNormal("ID no valida.", ancho, true);
	}

	system("pause");
	
}

void menuSesionIniciada_VerCarrito(int ancho, Cuenta &cuenta){
	
	vector<Producto> carritoCompras = cuenta.getCarritoCompras();
	
	if(carritoCompras.size() > 0){
		
		string mensaje = "Carrito de compras de " + cuenta.getUsuario(); 
		
		textoNormal(mensaje, ancho, true);
		
		for(int i = 0; i < carritoCompras.size(); i++){
			
			string mensaje = to_string(i + 1) + ". Nombre: " + carritoCompras[i].getNombre() + ", Descripción: " + carritoCompras[i].getDescripcion() + ", Precio: " + carritoCompras[i].getPrecio() + ", Stock: " + to_string(carritoCompras[i].getStock()) + ".";
			
			textoNormal(mensaje, ancho, true);
			
		}
	
		int finalizarCompra;
						
		textoNormal("", ancho, true);
		
		textoNormal("¿Desea finalizar la compra de sus productos?", ancho, true);
		
		textoNormal("Ingrese 1 para sí, o 2 para no: ", ancho, false);
		
		cin >> finalizarCompra;
		
		switch(finalizarCompra){
			
			case 1:{
					
				int pagarTodo;
						
				textoNormal("", ancho, true);
					
				textoNormal("¿Desea pagar todos los productos, o algunos en especifico.", ancho, true);
					
				textoNormal("Ingrese 1 para todos los productos, o 2 para escoger cuales desea: ", ancho, false);
					
				cin >> pagarTodo;
					
				switch(pagarTodo){
						
					case 1:{
							
						menuSesionIniciada_MetodosDePago(cuenta, ancho, carritoCompras);
							
						break;
					}
					case 2:{
							
						vector<Producto> productosAPagar;
							
						int id;
						
						textoNormal("", ancho, true);
							
						textoNormal("Ingrese el indicador del producto que desea pagar", ancho, true);
							
						do{
						
							textoNormal("", ancho, true);
								
							textoNormal("Ingrese el indicador del porducto, 0 para dejar de escoger: ", ancho, false);
								
							cin >> id;
								
							if(id > 0 && id <= carritoCompras.size()){
									
								productosAPagar.push_back(carritoCompras[id - 1]);
									
								textoNormal("Producto agregado con exito.", ancho, true);
									
							}else{
									
								textoNormal("Indicador de producto no valido.", ancho, true);
							}
							
						}while(id != 0);
							
						menuSesionIniciada_MetodosDePago(cuenta, ancho, productosAPagar);
							
						break;
					}
				}
				
				break;
			}
			case 2:{
					
				textoNormal("Volviendo al menú anterior.", ancho, true);
						
				break;
			}
			
			default:{
					
				textoNormal("Opción no valida, volviendo al menú anterior.", ancho, true);
				
				break;
			}
		}
		
	}else{
		
		string mensaje = "Carrito de compras de " + cuenta.getUsuario() + " vacio."; 
		
		textoNormal(mensaje, ancho, true);
		
	}
	
	system("Pause");
}

void menuSesionIniciada_AgregarProducto(vector <Producto> &productos, Cuenta &cuenta, int ancho){
	
	string usuario = cuenta.getUsuario();
	
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
	
	int idProducto;
	
	do{
		srand(time(0));
			
		idProducto = (rand() % 9 + 1 ) * 100000 + (rand() % 100000);
		
	}while(menuSesionIniciada_AgregarProducto_IDExiste(productos, idProducto));
	
	Producto producto;
	
	producto.agregarProducto(nombre, descripcion, precio, stock, to_string(idProducto));
	
	producto.guardarProductoEnArchivos(usuario);
	
	productos.push_back(producto);
	
	cuenta.agregarProductoEnVenta(producto);
	
	cuenta.guardarProductoEnVentaArchivo(producto);
	
	textoNormal("Producto agregado con exito.", ancho, true);
	
	system("Pause");
}

bool menuSesionIniciada_AgregarProducto_IDExiste(vector <Producto> productos, int id){
	
	for(int i = 0; i < productos.size(); i++){
		
		if(stoi(productos[i].getID()) == id){
			
			return true;
		}
	}
	
	return false;
}

void menuSesionIniciada_AgregarDireccion(Cuenta &cuenta, int ancho){

	Direccion nuevaDireccion;
	
	int masDatos;
	
	string direccionCompleta;
	
	string datosAdicionales = "";
	
	string puntosReferencia = "";
																
	textoNormal("Ingrese su dirección: ", ancho, false);
	
	cin.ignore();
	
	getline(cin, direccionCompleta);
	
	textoNormal("¿Posee datos adicionales que desee agregar?: ", ancho, true);
																
	textoNormal("Ingrese 1 para sí 2 para no: ", ancho, false);
	
	cin >> masDatos;
	
	if(masDatos == 1){
																
		textoNormal("Ingrese los datos adicionales (Torre, Interior, Etc...): ", ancho, false);
		
		cin.ignore();
		
		getline(cin, datosAdicionales);
		
	}
	
	textoNormal("¿Posee puntos de referencia que desee agregar?: ", ancho, true);
																
	textoNormal("Ingrese 1 para sí 2 para no: ", ancho, false);
	
	cin >> masDatos;
	
	if(masDatos == 1){
		
		textoNormal("Ingrese los puntos de referencia: ", ancho, false);
		
		cin.ignore();
		
		getline(cin, puntosReferencia);
		
	}
															
	nuevaDireccion.agregarDatosDireccion(direccionCompleta, datosAdicionales, puntosReferencia);

	cuenta.setDireccion(nuevaDireccion);
	
	cuenta.guardarDireccionArchivo(nuevaDireccion);

}

void menuSesionIniciada_Finalizar(Direccion direccionDeCompra, vector<Producto> productosComprados, Cuenta &cuenta, string medioDePago, int ancho){
	
	time_t ahora = time(0);
																	
	tm* fecha = localtime(&ahora);
																	
	string fechaCompra = to_string(fecha->tm_mday) + "/" + to_string(fecha->tm_mon + 1) + "/" + to_string(fecha->tm_year + 1900);
																	
	string direccion = direccionDeCompra.getDireccionCompleta();
	
	if(direccionDeCompra.getDatosAdicionales() != ""){
		
		direccion += ", " + direccionDeCompra.getDatosAdicionales();
	}
	
	if(direccionDeCompra.getPuntosDeReferencia() != ""){
		
		direccion += ", " + direccionDeCompra.getPuntosDeReferencia();
	}
																	
	for(int i = 0; i < productosComprados.size(); i++){
																		
		Compra compra;
																		
		compra.agregarCompra(productosComprados[i], fechaCompra, medioDePago, direccion);
																		
		compra.guardarEnArchivos(cuenta.getUsuario());
																		
	}
																
	cuenta.eliminarVariosProductosCarrito(productosComprados);
	
	menuSesionIniciada_ActualizarRegistrosCarrito(cuenta);
																	
	textoNormal("Compra realizada con exito.", ancho, true);
	
	
}

void menuSesionIniciada_Comprar(Cuenta &cuenta, int ancho, vector<Producto> productosComprados, string medioDePago){
		
	vector<Direccion> direccionesUsuario = cuenta.getDireccion();
													
	if(direccionesUsuario.size() > 0){
														
		if(direccionesUsuario.size() > 1){
																
			for(int i = 0; i < direccionesUsuario.size(); i++){
																	
				string mensaje = to_string(i + 1) + ". Direccion: " + direccionesUsuario[i].getDireccionCompleta()+ ", " + direccionesUsuario[i].getDatosAdicionales() + ", " + direccionesUsuario[i].getPuntosDeReferencia();
																	
				textoNormal(mensaje, ancho, true);
																	
			}
																
			int indicadorDireccion;
																
			textoNormal("Ingrese el id de la dirección, 0 si desea agregar otra dirección: ", ancho, false);
																
			cin >> indicadorDireccion;
																
			if(indicadorDireccion > 0 && indicadorDireccion <= direccionesUsuario.size()){
																	
				menuSesionIniciada_Finalizar(direccionesUsuario[indicadorDireccion - 1], productosComprados, cuenta, medioDePago ,ancho);
																	
			}else if(indicadorDireccion == 0){
																	
				menuSesionIniciada_AgregarDireccion(cuenta, ancho);
				
				Direccion direccionAgregada = cuenta.getDireccion()[direccionesUsuario.size()];
																	 
				menuSesionIniciada_Finalizar(direccionAgregada, productosComprados, cuenta, medioDePago ,ancho);
																	
			}else{
																	
				textoNormal("ID no encontrada.", ancho, true);
																	
			}
																
		}else{
															
			int confirmarDireccion;
															
			string mensaje = "¿Desea enviarlo a la dirección: " + direccionesUsuario[0].getDireccionCompleta() + ", " + direccionesUsuario[0].getDatosAdicionales() + ", " + direccionesUsuario[0].getPuntosDeReferencia() + "?";
															
			textoNormal(mensaje, ancho, true);
															
			textoNormal("Ingrese 0 para cancelar, 1 para sí, o 2 para agregar otra direccion: ", ancho, false);
															
			cin >> confirmarDireccion;
															
			switch(confirmarDireccion){
																
				case 0:{
																
					textoNormal("Volviendo al menú anterior", ancho, true);
																
					break;
				}
																
				case 1:{
																	
					menuSesionIniciada_Finalizar(direccionesUsuario[0], productosComprados, cuenta, medioDePago ,ancho);
																	
					break;
				}
															
				case 2:{
																 
					menuSesionIniciada_AgregarDireccion(cuenta, ancho);
				
					Direccion direccionAgregada = cuenta.getDireccion()[1];
																	 
					menuSesionIniciada_Finalizar(direccionAgregada, productosComprados, cuenta, medioDePago ,ancho);
																	
					break;
				}
															
				default:{
																
					textoNormal("Opción no valida", ancho, true);
																
					break;
				}
																
			}
														
		}
													
	}else{
		
		int agregarDireccion;
														
		textoNormal("No posee direcciones de entrega.", ancho, true);
														
		textoNormal("Ingrese 1 para agregar una dirección de compra, o 2 para cancelar la compra: ", ancho, false);
														
		cin >> agregarDireccion;
														
		switch(agregarDireccion){
														
			case 1:{
				
				menuSesionIniciada_AgregarDireccion(cuenta, ancho);
				
				Direccion direccionAgregada = cuenta.getDireccion()[0];
																 
				menuSesionIniciada_Finalizar(direccionAgregada, productosComprados, cuenta, medioDePago ,ancho);
															
				break;
			}
														
			case 2:{
															
				textoNormal("Volviendo al menú anterior.", ancho, true);
															
				break;
			}
														
			default:{
															
				textoNormal("Opción no valida.", ancho, true);
															
				break;
			}
														
														
		}
	}										
}

void menuSesionIniciada_ActualizarRegistrosCarrito(Cuenta &cuenta){
	
	vector<Producto> carritoActualizado = cuenta.getCarritoCompras();
	
	string rutaDatosCarrito = "../Cuentas/" + cuenta.getUsuario() + "/datos_carrito.csv";

	fstream modificarCarrito(rutaDatosCarrito, ios::out);
					
	for(int i = 0; i < carritoActualizado.size(); i++){
						
		modificarCarrito << carritoActualizado[i].getID() << endl;
		
	}	
	
	modificarCarrito.close();
	
}

void menuSesionIniciada_Comprar_PagoTarjeta(Cuenta &cuenta, int ancho, vector<Producto> productosComprar){
	
	vector<Tarjeta> tarjetasUsuario = cuenta.getTarjetas();
									
	if(tarjetasUsuario.size() > 0){
										
		int indicadorTarjeta;
										
		for (int j = 0; j < tarjetasUsuario.size(); j++) {
											
			string numeroTarjeta = tarjetasUsuario[j].getNumeroTarjeta();
											    
			string asteriscos(numeroTarjeta.size() - 4, '*');
											    
			string ultimosCuatro = numeroTarjeta.substr(numeroTarjeta.size() - 4);
											    
			string mensaje = to_string(j + 1) + ". Tarjeta: " + asteriscos + ultimosCuatro;
											    
			textoNormal(mensaje, ancho, true);
		
		}
										
		textoNormal("Ingrese el id de la tarjeta con la que desea pagar, 0 para cancelar la compra: ", ancho, false);
										
		cin >> indicadorTarjeta;
										
		if(indicadorTarjeta > 0 && indicadorTarjeta <= tarjetasUsuario.size()){
												
			string cvv;
													
			textoNormal("Ingrese su cvv para finalizar la compra: ", ancho, false);
													
			cin >> cvv;
													
			if(cvv == tarjetasUsuario[indicadorTarjeta - 1].getCvvTarjeta()){
													
				menuSesionIniciada_Comprar(cuenta, ancho, productosComprar, "Tarjeta");
													
			}else{
														
				textoNormal("cvv no valido.", ancho, true);
				
			}
												
		}else if(indicadorTarjeta == 0){
											
			textoNormal("Regresando al menú anterior.", ancho, true);
											
		}else{
											
			textoNormal("Indicador no valido", ancho, true);
			
		}
										
	}else{
										
		int agregarTarjeta;
										
		textoNormal("No posee tarjetas.", ancho, true);
										
		textoNormal("Ingrese 1 si desea agregar una tarjeta, o 2 para volver al menú anterior: ", ancho, false);
										
		cin >> agregarTarjeta;
										
		switch(agregarTarjeta){
											
			case 1:{
													
				Tarjeta _tarjeta;
																			
				_tarjeta = agregarTarjetaPorConsola(ancho);
														
				cuenta.setTarjeta(_tarjeta);
														
				cuenta.guardarTarjetaArchivo(_tarjeta);
														
				menuSesionIniciada_Comprar(cuenta, ancho, productosComprar, "Tarjeta");
														
				break;
			
			}case 2:{
												
				textoNormal("Volviendo al menú anterior.", ancho, true);
												
				break;
				
			}default:{
												
				textoNormal("Opción no valida.", ancho, true);
												
				break;
			
			}
											
		}
				
	}
}

void menuSesionIniciada_MetodosDePago(Cuenta &cuenta, int ancho, vector<Producto> productosComprar){
	
	double totalPedido = 0;
							
 	for(int i = 0; i < productosComprar.size(); i++){
								
		totalPedido += stod(productosComprar[i].getPrecio());
								
	}
							
	ostringstream oss;
							
	oss << fixed << setprecision(2) << totalPedido;
							
	string mensaje = "Total del pedido: " + to_string(totalPedido);
							
	textoNormal(mensaje, ancho, true);
							
	int opcion;
							
	textoNormal("0. Cancelar el pago.", ancho, true);
													
	textoNormal("1. Pago por tarjeta.", ancho, true);
							
	textoNormal("2. Pago contra entrega.", ancho, true);
							
	textoNormal("Ingrese una opción: ", ancho, false);
							
	cin >> opcion;
							
	switch(opcion){
							
		case 0:{
							
			textoNormal("Volviendo al menú anterior.", ancho, true);
										
			break;
		
		}case 1:{
									
			menuSesionIniciada_Comprar_PagoTarjeta(cuenta, ancho, productosComprar);
									
			break;
									
		}case 2:{
									
			menuSesionIniciada_Comprar(cuenta, ancho, productosComprar, "Pago Contra Entrega");
									
			break;
									
		}default:{
									
			textoNormal("Opción no valida.", ancho, true);
									
			break;
		}			
	}
}

void menuSesionIniciada_MostrarCompras(int ancho, vector<Compra> productosComprados){
	
	string mensaje;
	
	Producto productoComprado;
	
	if(productosComprados.size() > 0){
		
		for(int i = 0; i < productosComprados.size(); i++){
			
			productoComprado = productosComprados[i].getProductoComprado();
			
			mensaje = to_string(i + 1)	+ ". Nombre: " + productoComprado.getNombre() + ", Valor Compra: " + productoComprado.getPrecio() + ", Fecha: " + productosComprados[i].getFechaCompra() + ", Metodo De Pago: " + productosComprados[i].getMetodoDePago() + ".";
			
			textoNormal(mensaje, ancho, true);
			
		}
		
	}else{
		
		textoNormal("No tiene compras registradas.", ancho, true);
	}
	
	system("pause");
	
}

void menuSesionIniciada_EditarProducto(vector <Producto> &productos, Cuenta &cuenta, int ancho){
	
	vector<Producto> productosEnVenta = cuenta.getProductosEnVenta();
	
	if(productosEnVenta.size() > 0){
		
		string mensaje;
		
		int indicador;
		
		int posicionProductoOriginal;
		
		for(int i = 0; i < productosEnVenta.size(); i++){
		
			mensaje = to_string(i + 1) + ". Nombre: " + productosEnVenta[i].getNombre() + ", Descripción: " + productosEnVenta[i].getDescripcion() + ", Precio: " + productosEnVenta[i].getPrecio() + ", Stock: " + to_string(productosEnVenta[i].getStock()) + ".";
			
			textoNormal(mensaje, ancho, true);
			
		}
		
		textoNormal("Ingrese el indicador del produto a editar, 0 si no desea editar nada: ", ancho, false);
		
		cin >> indicador;
		
		if(indicador > 0 && indicador <= productosEnVenta.size()){
			
			Producto productoEditar;
			
			posicionProductoOriginal = conocerPosicionProductoPorID(stoi(productosEnVenta[indicador - 1].getID()), productos);
			
			productoEditar = productosEnVenta[indicador - 1];
			
			productoEditar.editarDatos(ancho, cuenta.getUsuario());
			
			cuenta.editarProductoVenta(productoEditar, indicador - 1);
			
			productos[posicionProductoOriginal] = productoEditar;
			
		}else{
			
			textoNormal("Indicador no valido.", ancho, true);
		}
		
	}else{
		
		textoNormal("No tienes productos en venta.", ancho, true);
		
	}
	
	system("pause");
	
}

void menuSesionIniciada_ConfiguracionCuenta(int ancho, vector<Cuenta> &cuentas, Cuenta &cuenta){
	
	int op;
	
	textoNormal("0. Volver al menú anterior.", ancho, true);
	
	textoNormal("1. Editar datos de la cuenta.", ancho, true);
	
	textoNormal("2. Agregar una tarjeta.", ancho, true);
	
	textoNormal("3. Agregar una dirección.", ancho, true);
	
	textoNormal("Ingrese el dato que desea modificar: ", ancho, false);
	
	cin >> op;
	
	cin.ignore();
	
	switch(op){
		
		case 0:{
			
			textoNormal("Volviendo la menú anterior", ancho, true);
			
			break;
		}
		
		case 1:{
			
			menuSesionIniciada_ConfiguracionCuenta_EditarCuenta(ancho, cuenta);
			
			int variableNoUsable;
			
			int posicionCuenta = busquedaPosicionCuenta(cuentas, cuenta.getUsuario(), variableNoUsable);
			
			cuentas[posicionCuenta] = cuenta;
			
			break;
		}
		
		case 2:{
			
			Tarjeta _tarjeta;
																			
			_tarjeta = agregarTarjetaPorConsola(ancho);
														
			cuenta.setTarjeta(_tarjeta);
														
			cuenta.guardarTarjetaArchivo(_tarjeta);
			
			int variableNoUsable;
			
			int posicionCuenta = busquedaPosicionCuenta(cuentas, cuenta.getUsuario(), variableNoUsable);
			
			cuentas[posicionCuenta] = cuenta;
			
			break;
		}
		
		case 3:{
			
			menuSesionIniciada_AgregarDireccion(cuenta, ancho);
			
			int variableNoUsable;
			
			int posicionCuenta = busquedaPosicionCuenta(cuentas, cuenta.getUsuario(), variableNoUsable);
			
			cuentas[posicionCuenta] = cuenta;
			
			break;
		}
		
		default:{
			
			textoNormal("Opción no valida.", ancho, true);
			
			break;
		}
	}
	
	system("pause");
	
}

void menuSesionIniciada_ConfiguracionCuenta_EditarCuenta(int ancho, Cuenta &cuenta){
	
	int op;
	
	bool datoCorrecto;
	
	textoNormal("1. Nombre.", ancho, true);
	
	textoNormal("2. Correo.", ancho, true);
	
	textoNormal("3. Contraseña", ancho, true);
	
	textoNormal("4. Celular", ancho, true);
	
	textoNormal("Ingrese el dato que desea modificar: ", ancho, false);
	
	cin >> op;
	
	cin.ignore();
	
	switch(op){
		
		case 1:{
			
			string nuevoNombre;
			
			textoNormal("Ingrese el nuevo nombre: ", ancho, false);
			
			getline(cin, nuevoNombre);
	
			datoCorrecto = nombreValido(nuevoNombre);
				
			if(!datoCorrecto){
					
				textoNormal("Nombre no valido.", ancho, true);
				
			}else{
				
				cuenta.editarNombre(nuevoNombre);
				
				textoNormal("Dato actualizado con exito.", ancho, true);
				
			}
			
			break;
		}
		
		case 2:{
			
			string nuevoCorreo;
			
			textoNormal("Ingrese el nuevo correo electronico: ", ancho, false);
	
			cin >> nuevoCorreo;
		
			datoCorrecto = correoValido(nuevoCorreo);
			
			if(!datoCorrecto){
				
				textoNormal("Correo electronico no valido.", ancho, true);
				
			}else{
				
				cuenta.editarCorreo(nuevoCorreo);
				
				textoNormal("Dato actualizado con exito.", ancho, true);
				
			}
			
			break;
		}
		
		case 3:{
			
			string nuevaClave;
			
			textoNormal("Ingrese la nueva contraseña: ", ancho, false);
		
			cin >> nuevaClave;
		
			datoCorrecto = claveValida(nuevaClave);
			
			if(!datoCorrecto){
				
				textoNormal("Contraseña no valida.", ancho, true);
			}else{
				
				cuenta.editarClave(nuevaClave);
				
				textoNormal("Dato actualizado con exito.", ancho, true);
				
			}
			
			break;
		}
		
		case 4:{
			
			string nuevoCelular;
			
			textoNormal("Ingrese el nuevo numero de celular: ", ancho, false);
	
			cin >> nuevoCelular;
		
			datoCorrecto = celularValido(nuevoCelular);
			
			if(!datoCorrecto){
				
				textoNormal("Numero de celular no valido.", ancho, true);
				
			}else{
				
				cuenta.editarCelular(nuevoCelular);
				
				textoNormal("Dato actualizado con exito.", ancho, true);
				
			}
			
			break;
		}
		
		default:{
			
			textoNormal("Opción no valida.", ancho, true);
			
			break;
		}
		
	}
	
}
