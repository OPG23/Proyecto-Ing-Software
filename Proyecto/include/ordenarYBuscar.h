#include <iostream>

#include <vector>

#include "cuentas.h"

using namespace std;

char minuscula(char l) {
	
    if (l >= 'A' && l <= 'Z') {
    	
        l = l + 32;
    }
    return l;
}

string aMinusculas(string texto) {
	
    string stringEnMinusculas = texto;

    for (size_t i = 0; i < stringEnMinusculas.length(); i++) {
    	
        stringEnMinusculas[i] = minuscula(stringEnMinusculas[i]);
    }

    return stringEnMinusculas;
}

void ordenarCuentas(vector<Cuenta> &cuentas,int inicio, int fin){
	
	int izq, der;
    
	string pivote;
	
	Cuenta aux;
    
	izq = inicio;
    
    der = fin;
    
    pivote = aMinusculas(cuentas[(izq+der)/2].getUsuario());
    

    do{
        while(aMinusculas(cuentas[izq].getUsuario()) < pivote && izq < fin){
            izq++;
        }

        while(aMinusculas(cuentas[der].getUsuario()) > pivote && der > inicio){
            der --;
        }

        if(izq <= der){
            aux = cuentas[izq];
            
            cuentas[izq] = cuentas[der];
            
            cuentas[der] = aux;
            
            izq++;
            
            der--;
        }

    }while(izq <= der);

    if(inicio < der){
        ordenarCuentas(cuentas,inicio,der);
    }

    if(fin > izq){
        ordenarCuentas(cuentas,izq,fin);
    }

}

bool busquedaCuentaLogin(vector<Cuenta> &cuentas, string usuario, string clave, Cuenta &cuenta){
	
	if(cuentas.size() > 0){
		
		usuario = aMinusculas(usuario);
	
		int inicio = 0;
		
		int fin = cuentas.size() - 1;
		
		while(inicio <= fin){
			
			int medio = inicio + (fin - inicio) / 2;
			
			if(aMinusculas(cuentas[medio].getUsuario()) == usuario){
				
				if(cuentas[medio].getClave() == clave){
					
					cuenta = cuentas[medio];
					
					return true;
					
				}else{
					
					return false;
				}
			}else if(aMinusculas(cuentas[medio].getUsuario()) < usuario){
				
				inicio = medio + 1;
			}else{
				
				fin = medio - 1;
			}
			
		}
		
	}
	
    return false;
	
}

int busquedaPosicionCuenta(vector<Cuenta> &cuentas, string usuario, int &ubicador) {
    
    usuario = aMinusculas(usuario);
    
    int inicio = 0;
    
    int fin = cuentas.size() - 1;
    
    int medio;
    
    while (inicio <= fin) {
    	
        medio = inicio + (fin - inicio) / 2;
        
        string usuarioMedio = aMinusculas(cuentas[medio].getUsuario());
        
        if (usuarioMedio == usuario) {
        	
            return medio;
            
        } else if (usuarioMedio < usuario) {
        	
            inicio = medio + 1;
        } else {
        	
            fin = medio - 1;
        }
    }
    
    ubicador = medio;
    
    return -1;
}

void ordenarProductosPorPrecioMenor(vector<Producto> &productos,int inicio, int fin){
	
	int izq, der;
    
	double pivote;
	
	Producto aux;
    
	izq = inicio;
    
    der = fin;
    
    pivote = stod(productos[(izq+der)/2].getPrecio());
    

    do{
        while(stod(productos[izq].getPrecio()) < pivote && izq < fin){
            izq++;
        }

        while(stod(productos[der].getPrecio()) > pivote && der > inicio){
            der --;
        }

        if(izq <= der){
            aux = productos[izq];
            
            productos[izq] = productos[der];
            
            productos[der] = aux;
            
            izq++;
            
            der--;
        }

    }while(izq <= der);

    if(inicio < der){
        ordenarProductosPorPrecioMenor(productos,inicio,der);
    }

    if(fin > izq){
        ordenarProductosPorPrecioMenor(productos,izq,fin);
    }

}

void ordenarProductosPorPrecioMayor(vector<Producto> &productos, int inicio, int fin) {
    
    int izq = inicio;
    
    int der = fin;
    
    double pivote = stod(productos[(izq + der) / 2].getPrecio());
    
    Producto aux;
    
    do {
       
        while(stod(productos[izq].getPrecio()) > pivote && izq <= fin) {
            izq++;
        }
        
        while(stod(productos[der].getPrecio()) < pivote && der >= inicio) {
            der--;
        }
        
        if (izq <= der) {
            
            aux = productos[izq];
            productos[izq] = productos[der];
            productos[der] = aux;
            
            izq++;
            der--;
        }
    } while (izq <= der);
    
    
    if (inicio < der) {
        ordenarProductosPorPrecioMayor(productos, inicio, der);
    }
    
    if (fin > izq) {
        ordenarProductosPorPrecioMayor(productos, izq, fin);
    }
}

void ordenarProductosPorNombre(vector<Producto> &productos,int inicio, int fin){
	
	int izq, der;
    
	string pivote;
	
	Producto aux;
    
	izq = inicio;
    
    der = fin;
    
    pivote = aMinusculas(productos[(izq+der)/2].getNombre());
    

    do{
        while(aMinusculas(productos[izq].getNombre()) < pivote && izq<fin){
            izq++;
        }

        while(aMinusculas(productos[der].getNombre()) > pivote && der > inicio){
            der --;
        }

        if(izq <= der){
            aux = productos[izq];
            
            productos[izq] = productos[der];
            
            productos[der] = aux;
            
            izq++;
            
            der--;
        }

    }while(izq <= der);

    if(inicio < der){
        ordenarProductosPorNombre(productos,inicio,der);
    }

    if(fin > izq){
        ordenarProductosPorNombre(productos,izq,fin);
    }

}

Producto busquedaPosicionProducto(vector<Producto> &productos, string nombreProducto, int ancho) {
    
    Producto noAgregarProducto;
    
    noAgregarProducto.agregarProducto("noAgregarProducto15478896587549852456586465132165489","","",0,"");
    
    if(productos.size() > 0){
    	
    	nombreProducto = aMinusculas(nombreProducto);
    
	    vector<Producto> productosOrdenados = productos;
	    
	    vector<Producto> productosEncontrados;
	    
	    ordenarProductosPorNombre(productosOrdenados, 0, productosOrdenados.size() - 1);
	    
	    int inicio = 0;
	    
	    int fin = productosOrdenados.size() - 1;
	    
	    int iterador = 1;
	    
	    while (inicio <= fin) {
	    	
	        int medio = inicio + (fin - inicio) / 2;
	        
	        string productoMedio = aMinusculas(productosOrdenados[medio].getNombre());
	        
	        if (productoMedio == nombreProducto) {
	        	
	        	string mensaje = to_string(iterador++) + ". Nombre: " + productosOrdenados[medio].getNombre() + ", Descripción: " + productosOrdenados[medio].getDescripcion() + ", Precio: " + productosOrdenados[medio].getPrecio() + ", Stock: " + to_string(productosOrdenados[medio].getStock()) + ".";
				
				productosEncontrados.push_back(productosOrdenados[medio]);
				
				productosOrdenados.erase(productosOrdenados.begin() + medio);
				
				textoNormal(mensaje, ancho, true);
				
				int izquierda = medio - 1;
		        
				while (izquierda >= inicio && aMinusculas(productosOrdenados[izquierda].getNombre()) == nombreProducto) {
		        	
		        	string mensaje = to_string(iterador++) + ". Nombre: " + productosOrdenados[izquierda].getNombre() + ", Descripción: " + productosOrdenados[izquierda].getDescripcion() + ", Precio: " + productosOrdenados[izquierda].getPrecio() + ", Stock: " + to_string(productosOrdenados[izquierda].getStock()) + ".";
		        	
		        	textoNormal(mensaje, ancho, true);
		        	
				    productosEncontrados.push_back(productosOrdenados[izquierda]);
		        
				    izquierda--;
		        
				}
		
		        int derecha = medio + 1;
		
		        while (derecha <= fin && aMinusculas(productosOrdenados[derecha].getNombre()) == nombreProducto) {
					
					string mensaje = to_string(iterador++) + ". Nombre: " + productosOrdenados[derecha].getNombre() + ", Descripción: " + productosOrdenados[derecha].getDescripcion() + ", Precio: " + productosOrdenados[derecha].getPrecio() + ", Stock: " + to_string(productosOrdenados[derecha].getStock()) + ".";
					
					textoNormal(mensaje, ancho, true);
					
		            productosEncontrados.push_back(productosOrdenados[derecha]);
		
		            derecha++;
		        }
	
	        	break;
	            
	        } else if (productoMedio < nombreProducto) {
	        	
	            inicio = medio + 1;
	            
	        } else {
	        	
	            fin = medio - 1;
	        }
	    }
	    
	    if(productosEncontrados.size() > 0){
	    	
	    	int posicionProducto;
	    	
	    	textoNormal("Ingrese el numero del producto que desea agregar, 0 si no desea agregar ninguno: ", ancho, false);
	    	
	    	cin >> posicionProducto;
	    	
	    	if(posicionProducto > 0 && posicionProducto <= productosEncontrados.size()){
	    		
	    		return productosEncontrados[posicionProducto - 1];
			
			}else if(posicionProducto == 0){
				
				textoNormal("Regresando al menú anterior.", ancho, true);
					
				return noAgregarProducto;
			}else{
				
				textoNormal("ID no encontrada.", ancho, true);
				
				return noAgregarProducto;
			}
		}else{
	    
	    	return noAgregarProducto;
			
		}
	}else{
		
		return noAgregarProducto;
		
	}
    
    
}

bool buscarProductoPorID(Producto &producto, int ID, vector<Producto> productos){
	
	for(int i = 0; i < productos.size(); i++){
		
		if(ID == stoi(productos[i].getID())){
			
			producto = productos[i];
			
			return true;
		}
	}
	
	return false;
	
}

int conocerPosicionProductoPorID(int ID, vector<Producto> productos){
	
	for(int i = 0; i < productos.size(); i++){
		
		if(ID == stoi(productos[i].getID())){
			
			return i;
		}
	}
	
	return -1;
	
}



