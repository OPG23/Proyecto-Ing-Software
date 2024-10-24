#include <iostream>

#include <vector>

#include "cuentas.h"

#include "productos.h"

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
    
    pivote = cuentas[(izq+der)/2].getUsuario();
    

    do{
        while(cuentas[izq].getUsuario() < pivote && izq<fin){
            izq++;
        }

        while(cuentas[der].getUsuario() > pivote && der > inicio){
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
	
	usuario = aMinusculas(usuario);
	
	int inicio = 0;
	
	int fin = cuentas.size() - 1;
	
	while(inicio <= fin){
		
		int medio = inicio + (fin - inicio) / 2;
		
		if(aMinusculas(cuentas[medio].getUsuario()) == usuario){
			
			if(cuentas[medio].getClave() == clave){
				
				cuenta = cuentas[medio];
				
				return true;
				
			}
		}else if(aMinusculas(cuentas[medio].getUsuario()) < usuario){
			
			inicio = medio + 1;
		}else{
			
			fin = medio - 1;
		}
		
	}
	
    return false;
	
}

int busquedaPosicionCuenta(vector<Cuenta> &cuentas, string usuario) {
    
    usuario = aMinusculas(usuario);
    
    int inicio = 0;
    
    int fin = cuentas.size() - 1;
    
    while (inicio <= fin) {
    	
        int medio = inicio + (fin - inicio) / 2;
        
        string usuarioMedio = aMinusculas(cuentas[medio].getUsuario());
        
        if (usuarioMedio == usuario) {
        	
            return -1;
        } else if (usuarioMedio < usuario) {
        	
            inicio = medio + 1;
        } else {
        	
            fin = medio - 1;
        }
    }
    
    
    return inicio;
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

void ordenarProductosPorPrecioMayor(vector<Producto> &productos,int inicio, int fin){
	
	int izq, der;
    
	double pivote;
	
	Producto aux;
    
	izq = inicio;
    
    der = fin;
    
    pivote = stod(productos[(izq+der)/2].getPrecio());
    

    do{
        while(stod(productos[izq].getPrecio()) > pivote && izq > fin){
            izq++;
        }

        while(stod(productos[der].getPrecio()) < pivote && der < inicio){
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
        ordenarProductosPorPrecioMayor(productos,inicio,der);
    }

    if(fin > izq){
        ordenarProductosPorPrecioMayor(productos,izq,fin);
    }

}
