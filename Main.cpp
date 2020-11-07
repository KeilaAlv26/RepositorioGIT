#include "tinyxml2.cpp"
#include "tinyxml2.h"
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <sstream>

using namespace tinyxml2;
using namespace std;

//Variables Globales
string gSumaCoordenadas = "";

int strTok (string pCadena, char delimitador)
{
    string nueva;
	int largo = pCadena.length();
	for (int i = 0; i < largo; i++){
		if (pCadena[i] == delimitador){
			nueva = pCadena.substr(i);
			return i;
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
	string retornoCoordenadas;
    int posicionDelimitador=0;
	int ascii=0;
	int cont=0;
	int largoPCoordenadas=pCoordenadas.length();
	while(posicionDelimitador != -1){
		posicionDelimitador = strTok (pCoordenadas, (char)' ');
		ascii=pCoordenadas[0];
		if(ascii != 109 && ascii != 122){
			retornoCoordenadas = retornoCoordenadas +  pCoordenadas.substr(0,posicionDelimitador) + ",";
		}
		pCoordenadas = pCoordenadas.substr(posicionDelimitador+1, largoPCoordenadas);
		cont++;
	} 
	retornoCoordenadas= retornoCoordenadas + "/";
	return retornoCoordenadas;
}

string floatToString (float number){
    std::ostringstream buff;
    buff<<number;
    return buff.str();
}

void getSumaCoordenadas(string pCoordenadas)
{
	int largoPCoordenadas=pCoordenadas.length();
	int posicionDelimitador=0;
	int contador=0;
	float sumaAnteriorX=0;
	float sumaAnteriorY=0;
	float suma=0;
	while(pCoordenadas != "/"){
		posicionDelimitador = strTok (pCoordenadas, (char)',');
		if(contador%2 == 0){ //si es una coordenada X
			suma = stof(pCoordenadas.substr(0, posicionDelimitador)) + sumaAnteriorX;
			sumaAnteriorX=suma;
			gSumaCoordenadas= gSumaCoordenadas + floatToString(suma) + ',';
		}else{
			suma = stof(pCoordenadas.substr(0, posicionDelimitador)) + sumaAnteriorY;
			sumaAnteriorY=suma;
			gSumaCoordenadas= gSumaCoordenadas + floatToString(suma) + ',';
		}
		contador++;
		pCoordenadas = pCoordenadas.substr(posicionDelimitador+1, largoPCoordenadas);
	}
	cout<<"\n"<<gSumaCoordenadas<<endl;
}


int main()
{
	string coordenadas;
	float prueba;
	string retorno;
	int posicion;
	coordenadas = leerSVG("world.svg", "Nicaragua");
	posicion=strTok(coordenadas, (char)',');
	retorno = getCoordenadas(coordenadas);
	cout<<retorno<<endl;
	getSumaCoordenadas(retorno);
	//cout<<"\n\n"<<gSumaCoordenadas<<endl;
	/*posicion = strTok (retorno, (char)',');
	prueba = stof(retorno.substr(0, posicion));
	cout<<"\n\n"<<prueba;*/


    return 0;
}