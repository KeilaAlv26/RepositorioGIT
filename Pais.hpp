#ifndef PAIS_HPP
#define PAIS_HPP
#include "Frontera.hpp"
#include "ListaCoordenadas.hpp"

using namespace std;


class Pais {
private: 
    int                 aCantidadFronteras;
    int                 aPosicionSVG;
    string              aIdPais;
    string              aColor;
    string              aNombre;
    Pais*               aSiguientePais;
    ListaCoordenadas*   aCoordenadas;
    Frontera*           aPrimeraFrontera;
    Frontera*           aUltimaFrontera;

public: 
Pais (){
    aCantidadFronteras  =0;
    aIdPais             ="";
    aColor              ="";
    aNombre             ="";
    aSiguientePais      =nullptr;
    aCoordenadas        =nullptr;
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

    ListaCoordenadas* getCoordenadas(){
        return aCoordenadas;
    }

    void setCoordenadas(ListaCoordenadas* pCoordenadas){
        aCoordenadas=pCoordenadas;
    }

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