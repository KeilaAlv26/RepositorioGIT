#ifndef COORDENADA_HPP
#define COORDENADA_HPP
using namespace std;

class Coordenada {
private: 
    Coordenada*             aSiguienteCoordenada;
    string                  aCoordenadaX;
    string                  aCoordenadaY;

public: 
Coordenada (){
    aSiguienteCoordenada    =nullptr;
    aCoordenadaX            ="";
    aCoordenadaY            ="";

}

    Coordenada* getSiguienteCoordenada(){
        return aSiguienteCoordenada;
    }

    void setSiguienteCoordenada(Coordenada* pSiguienteCoordenada){
        aSiguienteCoordenada=pSiguienteCoordenada;
    }

    string getCoordenadaEjeX(){
        return aCoordenadaX;
    }

    void setCoordenadaEjeX(string pCoordenadaX){
        aCoordenadaX=pCoordenadaX;
    }

    string getCoordenadaEjeY(){//DEBE SELECCIONAR EN EL PARAMETRO SOLO LOS X O SOLO LOS Y
        return aCoordenadaY;
    }

    void getCoordenadaEjeY(string pCoordenadaY){
        aCoordenadaY=pCoordenadaY;
    }

};
#endif
