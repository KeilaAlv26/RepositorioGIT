#include "tinyxml2.cpp"
#include "tinyxml2.h"
#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>

using namespace tinyxml2;

//Compara dos cadenas de caracteres
bool compararChar(const char *cadena1, const char *cadena2){
	int i = 0;
	while ( true ){
		if (cadena1[i] != 0 and cadena2[i] == 0){
			return false;
		}else if (cadena1[i] == 0 and cadena2[i] != 0){
			return false;
		}else if (cadena1[i] != cadena2[i]){
			return false;
		}else if (cadena1[i] == 0 and cadena2[i] == 0){
			return true;
		}
		i++;
	}
}

//Separar cadenas por medio del delimitador
char* strTok (char* cadena, char delimitador, char* token){
    char *nueva = (char*) malloc(sizeof(char) * 100);
	int largo = (int)strlen(cadena);
	for (int i = 0; i < largo; i++){
		if (cadena[i] == delimitador){
			token[i] = '\0';
			nueva = cadena + i+1;
			return nueva;
		} else {
			token[i] = cadena[i];
		}		
	} 
	return nueva;
}

//lee el ma
const char* leerSVG(const char *pFilename, char* pPaisBuscado){
	int cantidadPaises=211;
	const char *paisActual;
	const char *coordenadas = 0;
	bool entro = false;
	XMLDocument doc;
	doc.LoadFile(pFilename);
	XMLElement *paths = doc.RootElement()->FirstChildElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement(); //Primer path
	for(int indice=0; indice<cantidadPaises-1; indice++){
		paths = paths->NextSiblingElement();
		paisActual = paths->Attribute("data-name");

		if(compararChar(pPaisBuscado, paisActual)){
			entro=true;
			coordenadas = paths->Attribute("d");
			return coordenadas;
		}	
	}
	if(entro == false){
		std::cout <<"El pais buscado no fue encontrado";
		return 0;
	}else return 0;
	//doc.SaveFile(pFilename);
}

char* unirChar(char* a, char* b){
		int largo1 = 0;
		while(a[largo1]!=0){
			largo1++;
		}//while(a[largo1]!=0)
		int largo2 =0;
		while(b[largo2]!=0){
			largo2++;
		}//while(b[largo2]!=0)
		int total = largo1 + largo2;
		char *cadena = new char[total+1]();
		for (int i = 0; i < total; i++){
			if (i < largo1){
				cadena[i] = a[i];
			}else{
				cadena[i] = b[i-largo1];
			}//else
		}//for (int i = 0; i < total; i++)
		return cadena;
	}

void CopiarCadena (char* cadenaA, char* cadenaB){
	for (int i = 0; i < (int)strlen(cadenaB); i++){
		cadenaA[i] = cadenaB[i];
	} 
	//cadenaA[(int)strlen(cadenaB)] = '\0';
}

char* getCoordenadas(const char* pCoordenadas){
    char *antesDelimitador = (char*) malloc(sizeof(char) * 50);
    //char antesDelimitador=(char)'';
	char *retornoCoordenadas = (char*) malloc(sizeof(char) * 100);
    char *sobranteCoordenadas = (char*) malloc(sizeof(char) * 100);
	CopiarCadena (antesDelimitador, (char*)"");
	retornoCoordenadas = unirChar(antesDelimitador, (char*)"");
	int ascii=0;
	while(ascii != 122){
		sobranteCoordenadas = strTok ((char*)pCoordenadas, (char)' ', antesDelimitador);
		ascii=sobranteCoordenadas[0];
		std::cout<<"comparando "<<ascii<<std::endl;
		if(ascii != 122 && ascii != 109){
			std::cout<<"entro"<<std::endl;
			retornoCoordenadas = unirChar(retornoCoordenadas, antesDelimitador);
			retornoCoordenadas = unirChar(retornoCoordenadas, (char*)",");
			
		}
		ascii=sobranteCoordenadas[0];
		CopiarCadena ((char*)pCoordenadas, sobranteCoordenadas);
	} 
	std::cout<<"Retorno "<< retornoCoordenadas<<std::endl;
	return retornoCoordenadas;
}

	

int main()
{
	/*const char *coordenadas;
	char * cadena;
    char *cadena2 = (char*) malloc(sizeof(char) * 100);
    char *coordenadasXY = (char*) malloc(sizeof(char) * 100);
	coordenadas = leerSVG("world.svg", (char*)("Costa Rica"));
	cadena = strTok ((char*)coordenadas, ' ', cadena2);
	coordenadasXY = getCoordenadas((char*)coordenadas);*/

	XMLDocument doc;
	doc.LoadFile("world.svg");
	XMLElement *paths = doc.RootElement()->FirstChildElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement(); //Primer path
	paths->SetAttribute("pais", "celnuevoma");
	doc.SaveFile("world.svg");
	//cadena = strTok ((char*)cadena, ',', cadena2);
	//std::cout << "\n\n"<<"cadena " <<cadena;
	//std::cout << "\n\n" <<coordenadas;
	//std::cout << "\n\n"<< "cadena2 " <<cadena2;
	//std::cout << "\n\n"<< "coorXY " <<coordenadasXY;

	
    return 0;
}