#include <iostream>

#include <windows.h>

using namespace std;

int anchoVentana(){
	
	int ancho;
	
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    
    if (GetConsoleScreenBufferInfo(hConsole, &csbi))
    	
    	ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	
    return ancho;
}

void textoAscii (string texto, int anchoVentana){
	
	int ancho =  anchoVentana;
	
	int x = texto.size();
	
	x *= 4;
	
	x = (ancho - x)/2;
	
	if(texto.size() * 4 > ancho){
		
		int renglones = 1, tamanoTexto = texto.size() * 4, iterador = 0;
		
		while(tamanoTexto > ancho){
			
			tamanoTexto /= 2;
			
			renglones++;
		}
		
		string textos[renglones];
		
		for(int i = 0; i < renglones; i++){
			
			for(int j = 0; j < ancho / 4 - 1; j++){
				
				if(iterador < texto.size())
				
					textos[i] += texto[iterador++];
			}
			
			if(i != renglones -1)
			
				textos[i] += "-";
				
		}
		
		for(int i = 0; i < renglones; i++){
			
			textoAscii(textos[i], anchoVentana);
			
		}
		
	}else{
	
		for (int i = 0; i < texto.size(); i++){
			if (i == 0){
				for (int j = 0; j < x; j++){
					cout << " ";
				}
			}
			if (texto[i] == '1')
				cout << " ## "; 
			if (texto[i] == '2')
				cout << "### ";
			if (texto[i] == '3')
				cout << "### ";
			if (texto[i] == '4')
				cout << "# # ";
			if (texto[i] == '5')
				cout << "### ";
			if (texto[i] == '6')
				cout << "### ";
			if (texto[i] == '7')
				cout << "### ";
			if (texto[i] == '8')
				cout << "### ";
			if (texto[i] == '9')
				cout << "### ";
			if (texto[i] == '0')
				cout << "### ";
			if (texto[i] == 'A' || texto[i] == 'a')
				cout << " #  ";
			if (texto[i] == 'B' || texto[i] == 'b')
				cout << "##  ";
			if (texto[i] == 'C' || texto[i] == 'c')
				cout << " ## ";
			if (texto[i] == 'D' || texto[i] == 'd')
				cout << "##  ";
			if (texto[i] == 'E' || texto[i] == 'e')
				cout << "### ";
			if (texto[i] == 'F' || texto[i] == 'f')
				cout << "### ";
			if (texto[i] == 'G' || texto[i] == 'g')
				cout << " ## ";
			if (texto[i] == 'H' || texto[i] == 'h')
				cout << "# # ";
			if (texto[i] == 'I' || texto[i] == 'i')
				cout << "### ";
			if (texto[i] == 'J' || texto[i] == 'j')
				cout << " ## ";
			if (texto[i] == 'K' || texto[i] == 'k')
				cout << "# # ";
			if (texto[i] == 'L' || texto[i] == 'l')
				cout << "#   ";
			if (texto[i] == 'M' || texto[i] == 'm')
				cout << "# # ";
			if (texto[i] == 'N' || texto[i] == 'n')
				cout << "### ";
			if (texto[i] == 'Ñ' || texto[i] == 'ñ')
				cout << "*** ";
			if (texto[i] == 'O' || texto[i] == 'o')
				cout << " #  ";
			if (texto[i] == 'P' || texto[i] == 'p')
				cout << "##  ";
			if (texto[i] == 'Q' || texto[i] == 'q')
				cout << " #  ";
			if (texto[i] == 'R' || texto[i] == 'r')
				cout << "##  ";
			if (texto[i] == 'S' || texto[i] == 's')
				cout << " ## ";
			if (texto[i] == 'T' || texto[i] == 't')
				cout << "### ";
			if (texto[i] == 'U' || texto[i] == 'u')
				cout << "# # ";
			if (texto[i] == 'V' || texto[i] == 'v')
				cout << "# # ";
			if (texto[i] == 'W' || texto[i] == 'w')
				cout << "# # ";
			if (texto[i] == 'X' || texto[i] == 'x')
				cout << "# # ";
			if (texto[i] == 'Y' || texto[i] == 'y')
				cout << "# # ";
			if (texto[i] == 'Z' || texto[i] == 'z')
				cout << "### ";
			if (texto[i] == ' ')
				cout << "    ";
			if (texto[i] == '-')
				cout << "    ";
			if (texto[i] == '#')
				cout << "# # ";
		} cout << endl;
		
		for (int i = 0; i < texto.size(); i++){
			if (i == 0){
				for (int j = 0; j < x; j++){
					cout << " ";
				}
			}
			if (texto[i] == '1')
				cout << "# # ";
			if (texto[i] == '2')
				cout << "  # ";
			if (texto[i] == '3')
				cout << "  # ";
			if (texto[i] == '4')
				cout << "# # ";
			if (texto[i] == '5')
				cout << "#   ";
			if (texto[i] == '6')
				cout << "#   ";
			if (texto[i] == '7')
				cout << "  # ";
			if (texto[i] == '8')
				cout << "# # ";
			if (texto[i] == '9')
				cout << "# # ";
			if (texto[i] == '0')
				cout << "# # ";
			if (texto[i] == 'A' || texto[i] == 'a')
				cout << "# # ";
			if (texto[i] == 'B' || texto[i] == 'b')
				cout << "# # ";
			if (texto[i] == 'C' || texto[i] == 'c')
				cout << "#   ";
			if (texto[i] == 'D' || texto[i] == 'd')
				cout << "# # ";
			if (texto[i] == 'E' || texto[i] == 'e')
				cout << "#   ";
			if (texto[i] == 'F' || texto[i] == 'f')
				cout << "#   ";
			if (texto[i] == 'G' || texto[i] == 'g')
				cout << "#   ";
			if (texto[i] == 'H' || texto[i] == 'h')
				cout << "# # ";
			if (texto[i] == 'I' || texto[i] == 'i')
				cout << " #  ";
			if (texto[i] == 'J' || texto[i] == 'j')
				cout << "  # ";
			if (texto[i] == 'K' || texto[i] == 'k')
				cout << "# # ";
			if (texto[i] == 'L' || texto[i] == 'l')
				cout << "#   ";
			if (texto[i] == 'M' || texto[i] == 'm')
				cout << "### ";
			if (texto[i] == 'N' || texto[i] == 'n')
				cout << "# # ";
			if (texto[i] == 'Ñ' || texto[i] == 'ñ')
				cout << "### ";
			if (texto[i] == 'O' || texto[i] == 'o')
				cout << "# # ";
			if (texto[i] == 'P' || texto[i] == 'p')
				cout << "# # ";
			if (texto[i] == 'Q' || texto[i] == 'q')
				cout << "# # ";
			if (texto[i] == 'R' || texto[i] == 'r')
				cout << "# # ";
			if (texto[i] == 'S' || texto[i] == 's')
				cout << "#   ";
			if (texto[i] == 'T' || texto[i] == 't')
				cout << " #  ";
			if (texto[i] == 'U' || texto[i] == 'u')
				cout << "# # ";
			if (texto[i] == 'V' || texto[i] == 'v')
				cout << "# # ";
			if (texto[i] == 'W' || texto[i] == 'w')
				cout << "# # ";
			if (texto[i] == 'X' || texto[i] == 'x')
				cout << "# # ";
			if (texto[i] == 'Y' || texto[i] == 'y')
				cout << "# # ";
			if (texto[i] == 'Z' || texto[i] == 'z')
				cout << "  # ";
			if (texto[i] == ' ')
				cout << "    ";
			if (texto[i] == '-')
				cout << "    ";
			if (texto[i] == '#')
				cout << "### ";
		} cout << endl;
		
		for (int i = 0; i < texto.size(); i++){
			if (i == 0){
				for (int j = 0; j < x; j++){
					cout << " ";
				}
			}
			if (texto[i] == '1')
				cout << "  # ";
			if (texto[i] == '2')
				cout << "  # ";
			if (texto[i] == '3')
				cout << " ## ";
			if (texto[i] == '4')
				cout << "### ";
			if (texto[i] == '5')
				cout << "### ";
			if (texto[i] == '6')
				cout << "### ";
			if (texto[i] == '7')
				cout << " ## ";
			if (texto[i] == '8')
				cout << "### ";
			if (texto[i] == '9')
				cout << "### ";
			if (texto[i] == '0')
				cout << "# # ";
			if (texto[i] == 'A' || texto[i] == 'a')
				cout << "### ";
			if (texto[i] == 'B' || texto[i] == 'b')
				cout << "##  ";
			if (texto[i] == 'C' || texto[i] == 'c')
				cout << "#   ";
			if (texto[i] == 'D' || texto[i] == 'd')
				cout << "# # ";
			if (texto[i] == 'E' || texto[i] == 'e')
				cout << "##  ";
			if (texto[i] == 'F' || texto[i] == 'f')
				cout << "##  ";
			if (texto[i] == 'G' || texto[i] == 'g')
				cout << "# # ";
			if (texto[i] == 'H' || texto[i] == 'h')
				cout << "### ";
			if (texto[i] == 'I' || texto[i] == 'i')
				cout << " #  ";
			if (texto[i] == 'J' || texto[i] == 'j')
				cout << "  # ";
			if (texto[i] == 'K' || texto[i] == 'k')
				cout << "##  ";
			if (texto[i] == 'L' || texto[i] == 'l')
				cout << "#   ";
			if (texto[i] == 'M' || texto[i] == 'm')
				cout << "### ";
			if (texto[i] == 'N' || texto[i] == 'n')
				cout << "# # ";
			if (texto[i] == 'Ñ' || texto[i] == 'ñ')
				cout << "# # ";
			if (texto[i] == 'O' || texto[i] == 'o')
				cout << "# # ";
			if (texto[i] == 'P' || texto[i] == 'p')
				cout << "##  ";
			if (texto[i] == 'Q' || texto[i] == 'q')
				cout << "# # ";
			if (texto[i] == 'R' || texto[i] == 'r')
				cout << "##  ";
			if (texto[i] == 'S' || texto[i] == 's')
				cout << " #  ";
			if (texto[i] == 'T' || texto[i] == 't')
				cout << " #  ";
			if (texto[i] == 'U' || texto[i] == 'u')
				cout << "# # ";
			if (texto[i] == 'V' || texto[i] == 'v')
				cout << "# # ";
			if (texto[i] == 'W' || texto[i] == 'w')
				cout << "### ";
			if (texto[i] == 'X' || texto[i] == 'x')
				cout << " #  ";
			if (texto[i] == 'Y' || texto[i] == 'y')
				cout << " #  ";
			if (texto[i] == 'Z' || texto[i] == 'z')
				cout << " #  ";
			if (texto[i] == ' ')
				cout << "    ";
			if (texto[i] == '-')
				cout << "### ";
			if (texto[i] == '#')
				cout << "# # ";
		} cout << endl;
		
		for (int i = 0; i < texto.size(); i++){
			if (i == 0){
				for (int j = 0; j < x; j++){
					cout << " ";
				}
			}
			if (texto[i] == '1')
				cout << "  # ";
			if (texto[i] == '2')
				cout << " #  ";
			if (texto[i] == '3')
				cout << "  # ";
			if (texto[i] == '4')
				cout << "  # ";
			if (texto[i] == '5')
				cout << "  # ";
			if (texto[i] == '6')
				cout << "# # ";
			if (texto[i] == '7')
				cout << "  # ";
			if (texto[i] == '8')
				cout << "# # ";
			if (texto[i] == '9')
				cout << "  # ";
			if (texto[i] == '0')
				cout << "# # ";
			if (texto[i] == 'A' || texto[i] == 'a')
				cout << "# # ";
			if (texto[i] == 'B' || texto[i] == 'b')
				cout << "# # ";
			if (texto[i] == 'C' || texto[i] == 'c')
				cout << "#   ";
			if (texto[i] == 'D' || texto[i] == 'd')
				cout << "# # ";
			if (texto[i] == 'E' || texto[i] == 'e')
				cout << "#   ";
			if (texto[i] == 'F' || texto[i] == 'f')
				cout << "#   ";
			if (texto[i] == 'G' || texto[i] == 'g')
				cout << "# # ";
			if (texto[i] == 'H' || texto[i] == 'h')
				cout << "# # ";
			if (texto[i] == 'I' || texto[i] == 'i')
				cout << " #  ";
			if (texto[i] == 'J' || texto[i] == 'j')
				cout << "# # ";
			if (texto[i] == 'K' || texto[i] == 'k')
				cout << "# # ";
			if (texto[i] == 'L' || texto[i] == 'l')
				cout << "#   ";
			if (texto[i] == 'M' || texto[i] == 'm')
				cout << "# # ";
			if (texto[i] == 'N' || texto[i] == 'n')
				cout << "# # ";
			if (texto[i] == 'Ñ' || texto[i] == 'ñ')
				cout << "# # ";
			if (texto[i] == 'O' || texto[i] == 'o')
				cout << "# # ";
			if (texto[i] == 'P' || texto[i] == 'p')
				cout << "#   ";
			if (texto[i] == 'Q' || texto[i] == 'q')
				cout << " ## ";
			if (texto[i] == 'R' || texto[i] == 'r')
				cout << "# # ";
			if (texto[i] == 'S' || texto[i] == 's')
				cout << "  # ";
			if (texto[i] == 'T' || texto[i] == 't')
				cout << " #  ";
			if (texto[i] == 'U' || texto[i] == 'u')
				cout << "# # ";
			if (texto[i] == 'V' || texto[i] == 'v')
				cout << "# # ";
			if (texto[i] == 'W' || texto[i] == 'w')
				cout << "### ";
			if (texto[i] == 'X' || texto[i] == 'x')
				cout << "# # ";
			if (texto[i] == 'Y' || texto[i] == 'y')
				cout << " #  ";
			if (texto[i] == 'Z' || texto[i] == 'z')
				cout << "#   ";
			if (texto[i] == ' ')
				cout << "    ";
			if (texto[i] == '-')
				cout << "    ";
			if (texto[i] == '#')
				cout << "### ";
		} cout << endl;
		
		for (int i = 0; i < texto.size(); i++){
			if (i == 0){
			for (int j = 0; j < x; j++){
				cout << " ";
			}
		}
		if (texto[i] == '1')
			cout << "  # ";
		if (texto[i] == '2')
			cout << "### ";
		if (texto[i] == '3')
			cout << "### ";
		if (texto[i] == '4')
			cout << "  # ";
		if (texto[i] == '5')
			cout << "### ";
		if (texto[i] == '6')
			cout << "### ";
		if (texto[i] == '7')
			cout << "  # ";
		if (texto[i] == '8')
			cout << "### ";
		if (texto[i] == '9')
			cout << "### ";
		if (texto[i] == '0')
			cout << "### ";
		if (texto[i] == 'A' || texto[i] == 'a')
			cout << "# # ";
		if (texto[i] == 'B' || texto[i] == 'b')
			cout << "##  ";
		if (texto[i] == 'C' || texto[i] == 'c')
			cout << " ## ";
		if (texto[i] == 'D' || texto[i] == 'd')
			cout << "##  ";
		if (texto[i] == 'E' || texto[i] == 'e')
			cout << "### ";
		if (texto[i] == 'F' || texto[i] == 'f')
			cout << "#   ";
		if (texto[i] == 'G' || texto[i] == 'g')
			cout << " ## ";
		if (texto[i] == 'H' || texto[i] == 'h')
			cout << "# # ";
		if (texto[i] == 'I' || texto[i] == 'i')
			cout << "### ";
		if (texto[i] == 'J' || texto[i] == 'j')
			cout << " #  ";
		if (texto[i] == 'K' || texto[i] == 'k')
			cout << "# # ";
		if (texto[i] == 'L' || texto[i] == 'l')
			cout << "### ";
		if (texto[i] == 'M' || texto[i] == 'm')
			cout << "# # ";
		if (texto[i] == 'N' || texto[i] == 'n')
			cout << "# # ";
		if (texto[i] == 'Ñ' || texto[i] == 'ñ')
			cout << "# # ";
		if (texto[i] == 'O' || texto[i] == 'o')
			cout << " #  ";
		if (texto[i] == 'P' || texto[i] == 'p')
			cout << "#   ";
		if (texto[i] == 'Q' || texto[i] == 'q')
			cout << "  # ";
		if (texto[i] == 'R' || texto[i] == 'r')
			cout << "# # ";
		if (texto[i] == 'S' || texto[i] == 's')
			cout << "##  ";
		if (texto[i] == 'T' || texto[i] == 't')
			cout << " #  ";
		if (texto[i] == 'U' || texto[i] == 'u')
			cout << "### ";
		if (texto[i] == 'V' || texto[i] == 'v')
			cout << " #  ";
		if (texto[i] == 'W' || texto[i] == 'w')
			cout << "# # ";
		if (texto[i] == 'X' || texto[i] == 'x')
			cout << "# # ";
		if (texto[i] == 'Y' || texto[i] == 'y')
			cout << " #  ";
		if (texto[i] == 'Z' || texto[i] == 'z')
			cout << "### ";
		if (texto[i] == ' ')
			cout << "    ";
		if (texto[i] == '-')
			cout << "    ";
		if (texto[i] == '#')
			cout << "# # ";
		} cout << endl;
		
		cout << endl;
	}
}


void textoNormal (string texto, int anchoVentana, bool saltarLinea){
	
	int ancho =  anchoVentana;
	
	int x = texto.size();
	
	x = (ancho - x)/2;
	
	if(texto.size() > ancho){
		
		int renglones = 1, tamanoTexto = texto.size(), iterador = 0;
		
		while(tamanoTexto > ancho){
			
			tamanoTexto /= 2;
			
			renglones++;
		}
		
		string textos[renglones];
		
		for(int i = 0; i < renglones; i++){
			
			for(int j = 0; j < ancho - 1; j++){
				
				if(iterador < texto.size())
				
					textos[i] += texto[iterador++];
			}
			
			if(i != renglones -1)
			
				textos[i] += "-";
				
		}
		
		for(int i = 0; i < renglones; i++){
			
			if(i != renglones -1)
			
				textoNormal(textos[i], anchoVentana, true);
				
			else
			
				textoNormal(textos[i], anchoVentana, saltarLinea);
			
		}
	}else{
			
		for (int j = 0; j < x; j++){
				
			cout << " ";
						
		}
		
		cout << texto;
		
		if (saltarLinea){ 
		
			cout<< endl;
			
		}
	}
}
