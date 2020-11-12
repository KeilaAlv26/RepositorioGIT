#ifndef LISTAPAISES_HPP
#define LISTAPAISES_HPP
#include "Pais.hpp"
#include <iostream>
#include <cstring>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
using namespace std;

class ListaPaises {
private: 
    int             aCantidadPaises;
    Pais*           aPrimerPais;
    Pais*           aUltimoPais;

public: 
ListaPaises (){
    aCantidadPaises =0;
    aPrimerPais     =nullptr;
    aUltimoPais     =nullptr;
}

    int getCantidadPaises(){
        return aCantidadPaises;
    }

    void setCantidadPaises(){
        aCantidadPaises++;
    }

    Pais* getPrimerPais(){
        return aPrimerPais;
    }

    void setPrimerPais(Pais* pPrimerPais){
        aPrimerPais=pPrimerPais;
    }

    Pais* getUltimoPais(){
        return aUltimoPais;
    }

    void setUltimoPais(Pais* pUltimoPais){
        aUltimoPais=pUltimoPais;
    }

   

    void agregarPais(string pNombre, string pIdPais, string pColor, int pPosicionSVG, string pCoordenadas)
    {
		Pais* nuevoPais = new Pais();
        if(aPrimerPais != nullptr){
            aUltimoPais->setSiguientePais(nuevoPais);
            aUltimoPais=nuevoPais;
            nuevoPais->setSiguientePais(nullptr);
        }
        else {
            setPrimerPais(nuevoPais);
            setUltimoPais(nuevoPais);
            nuevoPais->setSiguientePais(nullptr);
        }
        setCantidadPaises();
        nuevoPais->setColor(pColor);
        nuevoPais->setIdPais(pIdPais);
        nuevoPais->setNombre(pNombre);
        nuevoPais->setPosicionSVG(pPosicionSVG);
        saveCoordenadas(nuevoPais, pCoordenadas);
    }

    void imprimirPaises()
    {
        for(Pais* actual=aPrimerPais; actual!= nullptr;actual=actual->getSiguientePais()){
            cout<<actual->getNombre()<<" "<<actual->getIdPais()<<" "<<actual->getColor()<<" "<<actual->getPosicionSVG()<<endl;
            imprimirCoordenadasX(actual);
            imprimirCoordenadasY(actual);
        }    
    }

    void imprimirCoordenadasX(Pais* pPais){
        cout<<"X ";
        for(Coordenada* temporal=pPais->getPrimeraCoordenadaX(); temporal!= nullptr; temporal=temporal->getSiguienteCoordenadaX()){
            cout<<temporal->getCoordenadaEjeX()<<", ";
        }
        cout<<"\n\n";
    }

    void imprimirCoordenadasY(Pais* pPais){
        cout<<"Y ";
        for(Coordenada* temporal=pPais->getPrimeraCoordenadaY(); temporal!= nullptr; temporal=temporal->getSiguienteCoordenadaY()){
            cout<<temporal->getCoordenadaEjeY()<<", ";
        }
        cout<<"\n\n";
    }

    string saveColor(string pCadenaSVG)
    {
        int primerDelimitador=strTok(pCadenaSVG, (char)':');
        pCadenaSVG=pCadenaSVG.substr(primerDelimitador+1, pCadenaSVG.length());
        int segundoDelimitador=strTok(pCadenaSVG, (char)';');
        pCadenaSVG=pCadenaSVG.substr(0, segundoDelimitador);
        return pCadenaSVG;
    }

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
            if(ascii != 109 && ascii != 122 && ascii != 108 && ascii!= 77){
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
        string sumaCoordenadas;
        while(pCoordenadas != "/"){
            posicionDelimitador = strTok (pCoordenadas, (char)',');
            if(contador%2 == 0){ //si es una coordenada X
                suma = stof(pCoordenadas.substr(0, posicionDelimitador)) + sumaAnteriorX;
                sumaAnteriorX=suma;
                sumaCoordenadas= sumaCoordenadas + floatToString(suma) + ',';
            }else{
                suma = stof(pCoordenadas.substr(0, posicionDelimitador)) + sumaAnteriorY;
                sumaAnteriorY=suma;
                sumaCoordenadas= sumaCoordenadas + floatToString(suma) + ',';
            }
            contador++;
            pCoordenadas = pCoordenadas.substr(posicionDelimitador+1, largoPCoordenadas);
        }
        sumaCoordenadas=sumaCoordenadas + "/";

        return sumaCoordenadas;
    }

    void saveCoordenadas(Pais* pPais, string pCoordenadas)
    {
        pCoordenadas=getCoordenadas(pCoordenadas);
        //cout<<pCoordenadas<<endl;
        pCoordenadas=getSumaCoordenadas(pCoordenadas);
        //cout<<pCoordenadas<<endl;
        float puntoCoordenada=0;
        int posicionDelimitador=0;
        int verificaXoY=0;
        //cout<<pCoordenadas<<endl;
        while(pCoordenadas != "/"){
            posicionDelimitador=strTok(pCoordenadas, (char)',');
            puntoCoordenada=stof(pCoordenadas.substr(0,posicionDelimitador));
            pCoordenadas=pCoordenadas.substr(posicionDelimitador+1, pCoordenadas.length());
            //cout<<puntoCoordenada<<" / ";
            addCoordenadas(pPais, puntoCoordenada, verificaXoY);
            verificaXoY++;
        }   
    }

    void addCoordenadas(Pais* pPais, float pCoordenada, int pPuntoXY){
        Coordenada* nuevaCoordenada=new Coordenada();
        if(pPuntoXY%2 == 0){//si es x
            if(pPais->getPrimeraCoordenadaX() != nullptr){
                pPais->getUltimaCoordenadaX()->setSiguienteCoordenadaX(nuevaCoordenada);
                pPais->setUltimaCoordenadaX(nuevaCoordenada);
                nuevaCoordenada->setSiguienteCoordenadaX(nullptr);
            }
            else {
                pPais->setPrimeraCoordenadaX(nuevaCoordenada);
                pPais->setUltimaCoordenadaX(nuevaCoordenada);
                nuevaCoordenada->setSiguienteCoordenadaX(nullptr);
            }
            nuevaCoordenada->setCoordenadaEjeX(pCoordenada);
        } else {
            if(pPais->getPrimeraCoordenadaY() != nullptr){
                pPais->getUltimaCoordenadaY()->setSiguienteCoordenadaY(nuevaCoordenada);
                pPais->setUltimaCoordenadaY(nuevaCoordenada);
                pPais->getUltimaCoordenadaY()->setSiguienteCoordenadaY(nullptr);

            }
            else{
                pPais->setPrimeraCoordenadaY(nuevaCoordenada);
                pPais->setUltimaCoordenadaY(nuevaCoordenada);
                nuevaCoordenada->setSiguienteCoordenadaY(nullptr);
            }
            nuevaCoordenada->setCoordenadaEjeY(pCoordenada);
        }
    }

void buscarFronteras(){
    for(Pais* actual=aPrimerPais; actual!= nullptr; actual=actual->getSiguientePais()){
        for(Pais* fronteraTemp=aPrimerPais; fronteraTemp!=nullptr; fronteraTemp=fronteraTemp->getSiguientePais()){
            if(actual->getPosicionSVG() != fronteraTemp->getPosicionSVG()){
                comparacionDeCoordenadas(actual, fronteraTemp);
            }
        }
    }
}

void comparacionDeCoordenadas(Pais* pPais, Pais* pFrontera){
    Coordenada* coordPaisY=pPais->getPrimeraCoordenadaY();
    bool esFrontera=false;
    for(Coordenada* coordPaisX=pPais->getPrimeraCoordenadaX(); coordPaisX!=nullptr; coordPaisX=coordPaisX->getSiguienteCoordenadaX()){
        esFrontera=comparacion2(coordPaisX, coordPaisY, pPais, pFrontera);
        if(esFrontera){
            break;
        }
        coordPaisY=coordPaisY->getSiguienteCoordenadaY();
    }
}

bool comparacion2(Coordenada* coordPaisX, Coordenada* coordPaisY, Pais* pPais, Pais* pFrontera){
    Coordenada* coordFronteraY=pFrontera->getPrimeraCoordenadaY();
    for(Coordenada* coordFronteraX=pFrontera->getPrimeraCoordenadaX(); coordFronteraX!= nullptr; coordFronteraX=coordFronteraX->getSiguienteCoordenadaX()){
        if((coordPaisX->getCoordenadaEjeX() - coordFronteraX->getCoordenadaEjeX()) >=-1 && (coordPaisX->getCoordenadaEjeX() - coordFronteraX->getCoordenadaEjeX()) <=1){
            if((coordPaisY->getCoordenadaEjeY() - coordFronteraY->getCoordenadaEjeY()) >=-1 && (coordPaisY->getCoordenadaEjeY() - coordFronteraY->getCoordenadaEjeY()) <=1){
                agregarFrontera(pPais, pFrontera);
                return true;
            }
            coordFronteraY=coordFronteraY->getSiguienteCoordenadaY();
        }
    }return false;
}




void agregarFrontera(Pais* pPais, Pais* pFrontera){
    Frontera* nuevaFrontera = new Frontera();
    if(pPais->getPrimeraFrontera() != nullptr){
        pPais->getUltimaFrontera()->setSiguienteFrontera(nuevaFrontera);
        pPais->setUltimaFrontera(nuevaFrontera );
        nuevaFrontera->setSiguienteFrontera(nullptr);
    }
    else {
        pPais->setPrimeraFrontera(nuevaFrontera);
        pPais->setUltimaFrontera(nuevaFrontera);
        nuevaFrontera->setSiguienteFrontera(nullptr);
    }
    nuevaFrontera->setColor(pFrontera->getColor());
    nuevaFrontera->setIdPais(pFrontera->getIdPais());
    nuevaFrontera->setNombre(pFrontera->getNombre());
    pPais->setCantidadFronteras();
}

void imprimirFronteras(){
    for(Pais* actual=aPrimerPais; actual!= nullptr; actual=actual->getSiguientePais()){
        for(Frontera* temporal=actual->getPrimeraFrontera(); temporal!=nullptr; temporal=temporal->getSiguienteFrontera()){
            cout<<actual->getNombre()<<" - "<<temporal->getNombre()<<endl;
        }
    }
}

//509.1,502.6,507.7,503.9,506,503.5,505.2,502.2,503.5,501.7,502.1,502.5,498.6,500.8,497.7,501.6,496.3,502.8,497.8,503.7,496.9,505.7,496.8,507.7,497.5,509,499.2,509.6,500.4,511.4,501.6,509.8,501.3,508,502.7,509.1,503,511,504.9,511.8,507,513.1,508.5,514.6,508.6,516,507.9,517.1,509,518.4,511.9,519.8,512.3,518.6,512.8,517.3,512.7,516.1,513.5,515.4,512.4,514.4,512.5,511.9,514.7,511.3,512.3,508.6,510.3,506,509.1,502.6,/
//514.1,476.8,512.2,476.6,511.3,477.5,509.3,478.3,507.9,478.3,506.6,479.1,505.5,478.8,504.6,477.9,504,478.1,503.2,479.6,502.7,479.5,502.4,480.8,500.3,482.6,499.2,483.3,498.6,484.1,497.1,482.8,495.7,484.5,494.5,484.5,493.2,484.7,493,487.8,492.2,487.8,491.4,489.3,489.6,489.6,489.2,490,488.3,489,487.6,490,490.2,492.9,492.4,494.9,493.4,497,495.9,499.6,497.7,501.6,498.6,500.8,502.1,502.5,503.5,501.7,505.2,502.2,506,503.5,507.7,503.9,509.1,502.6,508.3,501.5,508.2,499.8,509.4,498.2,509.2,496.5,509.9,493.8,510.8,493.1,510.9,490.3,510.7,488.6,511.1,485.8,512,483.3,513.4,481.1,513.1,478.8,513.5,477.4,514.1,476.8,/


};

#endif