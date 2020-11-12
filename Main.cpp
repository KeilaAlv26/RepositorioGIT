#include "tinyxml2.cpp"
#include "tinyxml2.h"
#include <iostream>
/*#include <cstring>
#include <string>
#include <stdio.h>
#include <sstream>*/
#include "ListaPaises.hpp"

using namespace tinyxml2;
using namespace std;

ListaPaises* gListaPaises = new ListaPaises();


//Variables Globales
/*string gSumaCoordenadas = "";

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

string getSumaCoordenadas(string pCoordenadas)
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
	return gSumaCoordenadas;
}*/

/*bool compararCoordenadas(string pCoordenadasPais, string pCoordenadasfrontera){
	int delimitadorPais=0;
	int delimitadorFrontera=0;
	float puntoPais=0;
	float puntoFrontera=0;
	for(){
		delimitadorPais=strTok(pCoordenadasPais, (char)',');
		delimitadorFrontera=strTok(pCoordenadasFrontera, (char)',');
		puntoPais=stof(pCoordenadasPais.substr(0, posicionDelimitador)) + sumaAnteriorX;
		
		for(){
			
		}
	}
}*/

void addCountry(const char *pFilename){
	string lista;
	int cantidadPaises=211;
	string nombrePais;
	string id;
	string color;
    string coordenada;// ="m 1025.7,303.8 -1.1,-5.2 -3.2,2.3 -1,2.3 1.4,4.2 2.4,1.2 1.5,-4.8 z m -31.5,-50.9 -2.4,-2.4 -2.2,-0.1 -0.7,-2.2 -4.3,1.2 -1.4,5.1 -11.3,4.8 -4.6,-2.6 1.4,7 -8.2,-1.6 -6.4,1.3 0.4,4.6 7.5,2.4 3.6,3.1 5.1,6.5 -1,12.3 -2.7,3.7 2,2.4 9.4,2.8 1.9,-1.3 5.7,2.8 6,-0.8 0.5,-3.7 7.4,-2 10,1.6 4.5,-3.4 0.5,-2.7 -2.7,-0.8 -1.5,-4.8 1.7,-1.8 -1.6,-2.4 0.2,-1.7 -1.8,-2.7 -2.4,0.9 0,-2.8 3.5,-3.5 -0.2,-1.6 2.3,0.6 1.3,-1 0.5,-4.5 2.3,-4.2 -7.1,-1.2 -2.4,-1.6 -1.4,0.1 -1.1,-0.5 -4.4,-2.8 -2.5,0.4 -3.4,-2.9 z";
    // = "m 1369.9,333.8 -5.4,0 -3.8,-0.5 -2.5,2.9 -2.1,0.7 -1.5,1.3 -2.6,-2.1 -1,-5.4 -1.6,-0.3 0,-2 -3.2,-1.5 -1.7,2.3 0.2,2.6 -0.6,0.9 -3.2,-0.1 -0.9,3 -2.1,-1.3 -3.3,2.1 -1.8,-0.8 -4.3,-1.4 -2.9,0 -1.6,-0.2 -2.9,-1.7 -0.3,2.3 -4.1,1.2 0.1,5.2 -2.5,2 -4,0.9 -0.4,3 -3.9,0.8 -5.9,-2.4 -0.5,8 -0.5,4.7 2.5,0.9 -1.6,3.5 2.7,5.1 1.1,4 4.3,1.1 1.1,4 -3.9,5.8 9.6,3.2 5.3,-0.9 3.3,0.8 0.9,-1.4 3.8,0.5 6.6,-2.6 -0.8,-5.4 2.3,-3.6 4,0 0.2,-1.7 4,-0.9 2.1,0.6 1.7,-1.8 -1.1,-3.8 1.5,-3.8 3,-1.6 -3,-4.2 5.1,0.2 0.9,-2.3 -0.8,-2.5 2,-2.7 -1.4,-3.2 -1.9,-2.8 2.4,-2.8 5.3,-1.3 5.8,-0.8 2.4,-1.2 2.8,-0.7 -1.4,-1.9 z";
	XMLDocument doc;
	doc.LoadFile(pFilename);
	XMLElement *paths = doc.RootElement()->FirstChildElement()->NextSiblingElement()->NextSiblingElement(); //Primer path

	for(int indice=0; indice<cantidadPaises; indice++){
		paths = paths->NextSiblingElement();
		nombrePais = (string) paths->Attribute("data-name");
		//cout<<nombrePais<<endl;	
		id = (string) paths->Attribute("data-id");	
		color = gListaPaises->saveColor((string) paths->Attribute("style"));
		coordenada = (string) paths->Attribute("d");
		gListaPaises->agregarPais(nombrePais, id, color, indice+1, coordenada);
	}
	//gListaPaises->imprimirPaises();
	gListaPaises->buscarFronteras();
	gListaPaises->imprimirFronteras();

}


int main()
{

	addCountry("world.svg");
	/*string coordenadas;
	float prueba;
	string retorno;
	int posicion;
	string sumaCoordenadas;
	coordenadas = leerSVG("world.svg", "Nicaragua");
	posicion=strTok(coordenadas, (char)',');
	retorno = getCoordenadas(coordenadas);
	cout<<retorno<<endl;
	sumaCoordenadas = getSumaCoordenadas(retorno);
	cout<<"\n\n"<<sumaCoordenadas<<endl;*/
	/*posicion = strTok (retorno, (char)',');
	prueba = stof(retorno.substr(0, posicion));
	cout<<"\n\n"<<prueba;*/


    return 0;
}