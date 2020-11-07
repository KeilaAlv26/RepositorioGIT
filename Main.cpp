#include "tinyxml2.cpp"
#include "tinyxml2.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>

using namespace tinyxml2;
using namespace std;

int strTok (string pCadena, char delimitador, string token)
{
    string nueva;
	int largo = pCadena.length();
	for (int i = 0; i < largo; i++){
		if (pCadena[i] == delimitador){
			nueva = pCadena.substr(i);
			return i;
		} else {
			token = token + pCadena[i];
		}		
	}return -1;
}

string leerSVG(const char *pFilename, string pPaisBuscado)
{
	int cantidadPaises=211;
	bool entro = false;
	string paisActual;
	string coordenadas;
	XMLDocument doc;
	doc.LoadFile(pFilename);
	XMLElement *paths = doc.RootElement()->FirstChildElement()->NextSiblingElement()->NextSiblingElement()->NextSiblingElement(); //Primer path
	for(int indice=0; indice<cantidadPaises-1; indice++){
		paths = paths->NextSiblingElement();
		paisActual = (string) paths->Attribute("data-name");
		if(pPaisBuscado == paisActual){
			entro=true;
			coordenadas = (string) paths->Attribute("d");
			return coordenadas;
		}	
	}
	if(!entro){
		std::cout <<"El pais buscado no fue encontrado";
		return 0;
	}else return 0;
	//doc.SaveFile(pFilename);
}

string getCoordenadas(string pCoordenadas)
{
    string antesDelimitador;
	string retornoCoordenadas;
    int posicionDelimitador=0;
	int ascii=0;
	int cont=0;
	int largoPCoordenadas=pCoordenadas.length();
	while(posicionDelimitador != -1){
		posicionDelimitador = strTok (pCoordenadas, (char)' ', antesDelimitador);
		ascii=pCoordenadas[0];
		if(ascii != 109 && ascii != 122){
			retornoCoordenadas = retornoCoordenadas +  pCoordenadas.substr(0,posicionDelimitador) + ",";
		}
		pCoordenadas = pCoordenadas.substr(posicionDelimitador+1, largoPCoordenadas);
		cont++;
	} return retornoCoordenadas;
}


int main()
{
	string coordenadas;
	string temp;
	string retorno;
	coordenadas = leerSVG("world.svg", "Costa Rica");
	retorno=strTok(coordenadas, (char)',', temp);
	retorno = getCoordenadas(coordenadas);
	cout<<retorno;
    return 0;
}