#ifndef LISTACOORDENADAS_HPP
#define LISTACOORDENADAS_HPP
#include "Coordenada.hpp"
using namespace std;


class ListaCoordenadas {
private: 
   Coordenada* aPrimeraCoordenada;
   Coordenada* aUltimaCoordenada;

public: 
ListaCoordenadas (){
    aPrimeraCoordenada= nullptr;
    aUltimaCoordenada= nullptr;
}

    Coordenada* getPrimeraCoordenada(){
        return aPrimeraCoordenada;
    }

    void setPrimeraCoordenada(Coordenada* pPrimeraCoordenada){
        aPrimeraCoordenada=pPrimeraCoordenada;
    }

    Coordenada* getUltimaCoordenada(){
        return aUltimaCoordenada;
    }

    void setUltimaCoordenada(Coordenada* pUltimaCoordenada){
        aUltimaCoordenada=pUltimaCoordenada;
    }
   



};

#endif