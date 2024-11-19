#include <iostream>

#include <string>

#include "../include/menus.h"

using namespace std;

void agregarCuentasDelArchivo(vector<Cuenta> &cuentas, vector<Producto> productos);

void agregarProductosDelArchivo(vector<Producto> &productos);


int main(){
	
	setlocale(LC_ALL, "SPANISH");
	
	system("mkdir ..\\Cuentas\\");
	
	vector<Cuenta> cuentas;
	
	vector<Producto> productos;
	
	agregarProductosDelArchivo(productos);
	
	agregarCuentasDelArchivo(cuentas, productos);
	
	if(cuentas.size() > 1){
		
		ordenarCuentas(cuentas, 0, cuentas.size() - 1);
	}
	
	
    menuPrincipal(cuentas, productos);
    
    return 0;
}

void agregarCuentasDelArchivo(vector<Cuenta> &cuentas, vector<Producto> productos){
	
	string carpetaProductos = "..\\Cuentas\\*";
   	
    WIN32_FIND_DATA informacionCarpeta;
    
    HANDLE carpetaEncontrada = FindFirstFile(carpetaProductos.c_str(), &informacionCarpeta);
	
	do {
        	
        if (informacionCarpeta.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            	
            string nombreCarpeta = informacionCarpeta.cFileName;
                
            if (nombreCarpeta != "." && nombreCarpeta != "..") {
            	
            	string nombre, correo, celular, usuario, clave, numeroTarjeta, cvvTarjeta, fechaVencimiento, nombreTitularTarjeta;
            	
            	bool modificarCarrito = false;
            	
            	vector<int> idsCarrito;
               	
                string rutaDatosUsuarioCuenta = "..\\Cuentas\\" + nombreCarpeta + "\\datos_cuenta.csv";
               	
                string rutaDatosTarjetaCuenta = "..\\Cuentas\\" + nombreCarpeta + "\\datos_tarjeta.csv";
               	
                string rutaDatosCarritoCuenta = "..\\Cuentas\\" + nombreCarpeta + "\\datos_carrito.csv";
                
                string rutaDireccionesCuenta = "..\\Cuentas\\" + nombreCarpeta + "\\datos_direccion.csv";
                
                string rutaProductosComprados = "..\\Cuentas\\" + nombreCarpeta + "\\datos_productos_comprados.csv";
                
                string rutaProductosEnVenta = "..\\Cuentas\\" + nombreCarpeta + "\\datos_productos_venta.csv";
                
                fstream registrosDatosUsuarioCuenta(rutaDatosUsuarioCuenta);
                
                fstream registrosDatosTarjetaCuenta(rutaDatosTarjetaCuenta);
                
                fstream registrosDatosCarritoCuenta(rutaDatosCarritoCuenta);
                
                fstream registrosDatosDirecionesCuenta(rutaDireccionesCuenta);
                
                fstream registrosDatosProductosComprados(rutaProductosComprados);
                
                fstream registrosDatosProductosEnVenta(rutaProductosEnVenta);
                
				string linea;
		
				getline(registrosDatosUsuarioCuenta, linea);
		
				getline(registrosDatosUsuarioCuenta, linea);
					
				stringstream Linea (linea);
					
				getline(Linea, nombre, ';');
					
				getline(Linea, correo, ';');
					
				getline(Linea, celular, ';');
					
				getline(Linea, usuario, ';');
					
				getline(Linea, clave, ';');
		
				getline(registrosDatosTarjetaCuenta, linea);
                
				Cuenta cuenta;
				
				cuenta.agregarDatos(usuario, clave, nombre, correo, celular);
				
				while(getline(registrosDatosTarjetaCuenta, linea)){
							
					string numeroTarjeta;
					
					string cvvTarjeta;
					
					string fechaVencimiento;
					
					string nombreTitularTarjeta;
						
					stringstream Linea (linea);
				
					getline(Linea, numeroTarjeta, ';');
					
					getline(Linea, cvvTarjeta, ';');
					
					getline(Linea, fechaVencimiento, ';');
					
					getline(Linea, nombreTitularTarjeta, ';');
					
					if(numeroTarjeta != ""){
						
						Tarjeta tarjeta;
						
						tarjeta.agregarTarjeta(numeroTarjeta, cvvTarjeta, fechaVencimiento, nombreTitularTarjeta);
						
						cuenta.setTarjeta(tarjeta);
						
					}
					
				}
				
				while(getline(registrosDatosCarritoCuenta, linea)){
					
					string id;
					
					stringstream Linea (linea);
					
					getline(Linea, id);
					
					Producto producto;
					
					if(buscarProductoPorID(producto, stoi(id), productos)){
						
						cuenta.agregarProductoCarrito(producto);
						
						idsCarrito.push_back(stoi(id));
						
					}else{
						
						modificarCarrito = true;
					}
				}
				
				if(modificarCarrito){
					
					fstream modificarCarrito(rutaDatosCarritoCuenta, ios::out);
					
					for(int i = 0; i < idsCarrito.size(); i++){
						
						modificarCarrito << idsCarrito[i] << endl;
					}
					
				}
				
				getline(registrosDatosDirecionesCuenta, linea);
				
				while(getline(registrosDatosDirecionesCuenta, linea)){
					
					string direccionCompleta;
					
					string datosAdicionales;
					
					string puntosDeRefetencia;
					
					stringstream Linea (linea);
					
					getline(Linea, direccionCompleta, ';');
					
					getline(Linea, datosAdicionales, ';');
					
					getline(Linea, puntosDeRefetencia, ';');
					
					if(direccionCompleta != ""){
						
						Direccion direccion;
						
						direccion.agregarDatosDireccion(direccionCompleta, datosAdicionales, puntosDeRefetencia);
						
						cuenta.setDireccion(direccion);
						
					}
					
				}
				
				getline(registrosDatosProductosComprados, linea);
				
				while(getline(registrosDatosProductosComprados, linea)){
					
					string nombreDelProducto, valorTransaccion, medioDePago, fecha, direccionDeEntrega, idProducto, idCompra;
					
					stringstream Linea (linea);
					
					getline(Linea, nombreDelProducto, ';');
					
					getline(Linea, valorTransaccion, ';');
					
					getline(Linea, medioDePago, ';');
					
					getline(Linea, fecha, ';');
					
					getline(Linea, direccionDeEntrega, ';');
					
					getline(Linea, idProducto, ';');
					
					Producto producto;
					
					bool variableNoUsable = buscarProductoPorID(producto, stoi(idProducto), productos);
					
					Compra compra;
					
					compra.agregarCompra(producto, fecha, medioDePago, direccionDeEntrega);
					
					cuenta.agregarProductoComprado(compra);
				}
				
				while(getline(registrosDatosProductosEnVenta, linea)){
					
					string idProducto;
					
					int posicionProducto = 0;
					
					stringstream Linea (linea);
					
					getline(Linea, idProducto);
					
					if(idProducto != ""){
					
						posicionProducto = conocerPosicionProductoPorID(stoi(idProducto), productos);
					
						cuenta.agregarProductoEnVenta(productos[posicionProducto]);
						
					}
					
				}
                
				
				cuentas.push_back(cuenta);
				
				registrosDatosUsuarioCuenta.close();
				
				registrosDatosTarjetaCuenta.close();
				
				registrosDatosCarritoCuenta.close();
				
                registrosDatosDirecionesCuenta.close();
                
                registrosDatosProductosComprados.close();
				
				registrosDatosProductosEnVenta.close();
            }
        }
    } while (FindNextFile(carpetaEncontrada, &informacionCarpeta) != 0);
        
    FindClose(carpetaEncontrada);
	
}

void agregarProductosDelArchivo(vector<Producto> &productos){
	
	string carpetaProductos = "..\\Productos\\*";
   	
    WIN32_FIND_DATA informacionCarpeta;
    
    HANDLE carpetaEncontrada = FindFirstFile(carpetaProductos.c_str(), &informacionCarpeta);
	
	do {
        	
        if (informacionCarpeta.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            	
            string nombreCarpeta = informacionCarpeta.cFileName;
                
            if (nombreCarpeta != "." && nombreCarpeta != "..") {
               	
                string rutaProductosUsuarios = "..\\Productos\\" + nombreCarpeta + "\\*";
                
                WIN32_FIND_DATA informacionArchivos;
                
                HANDLE archivoEncontrado = FindFirstFile(rutaProductosUsuarios.c_str(), &informacionArchivos);
                
                do {
                	
                	if (!(informacionArchivos.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                		
	                    string rutaRegistroProducto = "..\\Productos\\" + nombreCarpeta + "\\" + informacionArchivos.cFileName;
	                    
	                    fstream registroProducto (rutaRegistroProducto);
	                    
	                    string linea, nombre, descripcion, precio, stock, id;
			
						getline(registroProducto, linea);
						
						getline(registroProducto, linea);
						
						stringstream Linea (linea);
						
						getline(Linea, nombre, ';');
						
						getline(Linea, descripcion, ';');
						
						getline(Linea, precio, ';');
						
						getline(Linea, stock, ';');
						
						getline(Linea, id, ';');
						
						Producto producto;
						
						producto.agregarProducto(nombre, descripcion, precio, stoi(stock), id);
						
						productos.push_back(producto);
                	}
                	
                } while (FindNextFile(archivoEncontrado, &informacionArchivos) != 0);
                
                FindClose(archivoEncontrado);
            }
        }
    } while (FindNextFile(carpetaEncontrada, &informacionCarpeta) != 0);
        
    FindClose(carpetaEncontrada);
	
}
