#include "cuarto.h"

Cuarto::Cuarto() : cuartoMonstruo() {}

Cuarto::Cuarto(Monstruo& monstruo) : cuartoMonstruo(monstruo){}
 
Cuarto::~Cuarto(){
}

std::ostream& operator<<(std::ostream& os, Cuarto& Cuarto){
    os << "Cuarto con: " << Cuarto.cuartoMonstruo;
        return os;
}