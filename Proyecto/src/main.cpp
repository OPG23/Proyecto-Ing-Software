#include <iostream>

#include "../include/menus.h"

using namespace std;

void agregarCuentasDelArchivo(vector<Cuenta> &cuentas);

void agregarProductosDelArchivo(vector<Producto> &productos);

int main(){
	
	setlocale(LC_ALL, "SPANISH");
	
	vector<Cuenta> cuentas;
	
	vector<Producto> productos;
	
	agregarCuentasDelArchivo(cuentas);
	
	agregarProductosDelArchivo(productos);

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
	                    
	                    string linea, nombre, descripcion, precio, stock;
			
						getline(registroProducto, linea);
						
						getline(registroProducto, linea);
						
						stringstream Linea (linea);
						
						getline(Linea, nombre, ';');
						
						getline(Linea, descripcion, ';');
						
						getline(Linea, precio, ';');
						
						getline(Linea, stock, ';');
						
						Producto producto;
						
						producto.agregarProducto(nombre, descripcion, precio, stoi(stock));
						
						productos.push_back(producto);
                	}
                	
                } while (FindNextFile(archivoEncontrado, &informacionArchivos) != 0);
                
                FindClose(archivoEncontrado);
            }
        }
    } while (FindNextFile(carpetaEncontrada, &informacionCarpeta) != 0);
        
    FindClose(carpetaEncontrada);
	
}
