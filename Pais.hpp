#ifndef PAIS_HPP
#define PAIS_HPP
#include "Frontera.hpp"
#include "Coordenada.hpp"

using namespace std;


class Pais {
private: 
    int                 aCantidadFronteras;
    int                 aPosicionSVG;
    string              aIdPais;
    string              aColor;
    string              aNombre;
    Pais*               aSiguientePais;
    Coordenada*         aPrimeraCoordenadaX;
    Coordenada*         aUltimaCoordenadaX;
    Coordenada*         aPrimeraCoordenadaY;
    Coordenada*         aUltimaCoordenadaY;
    Frontera*           aPrimeraFrontera;
    Frontera*           aUltimaFrontera;

public: 
Pais (){
    aCantidadFronteras  =0;
    aIdPais             ="";
    aColor              ="";
    aNombre             ="";
    aSiguientePais      =nullptr;
    aPrimeraCoordenadaX =nullptr;
    aUltimaCoordenadaX  =nullptr;
    aPrimeraCoordenadaY =nullptr;
    aUltimaCoordenadaY  =nullptr;
    aPrimeraFrontera    =nullptr;
    aUltimaFrontera     =nullptr;
}

    int getPosicionSVG(){
        return aPosicionSVG;
    }

    void setPosicionSVG(int pPosicionSVG){
        aPosicionSVG=pPosicionSVG;
    }

    int getCantidadFronteras(){
        return aCantidadFronteras;
    }

    void setCantidadFronteras(){
        aCantidadFronteras++;
    }

    string getIdPais(){
        return aIdPais;
    }

    void setIdPais(string pId){
        aIdPais=pId;
    }

    string getColor(){
        return aColor;
    }

    void setColor(string pColor){
        aColor=pColor;
    }

    string getNombre(){
        return aNombre;
    }

    void setNombre(string pNombre){
        aNombre=pNombre;
    }

    Pais* getSiguientePais(){
        return aSiguientePais;
    }

    void setSiguientePais(Pais* pPais){
        aSiguientePais = pPais;
    }

/////

    Coordenada* getPrimeraCoordenadaX(){
        return aPrimeraCoordenadaX;
    }

    void setPrimeraCoordenadaX(Coordenada* pPrimeraCoordenada){
        aPrimeraCoordenadaX=pPrimeraCoordenada;
    }

    Coordenada* getUltimaCoordenadaX(){
        return aUltimaCoordenadaX;
    }

    void setUltimaCoordenadaX(Coordenada* pUltimaCoordenada){
        aUltimaCoordenadaX=pUltimaCoordenada;
    }


////

/////

    Coordenada* getPrimeraCoordenadaY(){
        return aPrimeraCoordenadaY;
    }

    void setPrimeraCoordenadaY(Coordenada* pPrimeraCoordenada){
        aPrimeraCoordenadaY=pPrimeraCoordenada;
    }

    Coordenada* getUltimaCoordenadaY(){
        return aUltimaCoordenadaY;
    }

    void setUltimaCoordenadaY(Coordenada* pUltimaCoordenada){
        aUltimaCoordenadaY=pUltimaCoordenada;
    }


////

    Frontera* getPrimeraFrontera(){
        return aPrimeraFrontera;
    }

    void setPrimeraFrontera(Frontera* pPrimeraFrontera){
        aPrimeraFrontera=pPrimeraFrontera;
    }

    Frontera* getUltimaFrontera(){
        return aUltimaFrontera;
    }

    void setUltimaFrontera(Frontera* pUltimaFrontera){
        aUltimaFrontera=pUltimaFrontera;
    }


};

#endif