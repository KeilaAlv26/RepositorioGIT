#ifndef FRONTERA_HPP
#define FRONTERA_HPP

class Frontera {
private: 
    Frontera* aSiguienteFrontera;

public: 
Frontera (){
    aSiguienteFrontera=nullptr;
}

    Frontera* getSiguienteFrontera(){
        return aSiguienteFrontera;
    }

    void setSiguienteFrontera(Frontera* pSiguienteFrontera){
        aSiguienteFrontera=pSiguienteFrontera;
    }

};

#endif