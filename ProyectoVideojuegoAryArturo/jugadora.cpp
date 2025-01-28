#include "jugadora.h"

//constructor inicializador
Jugadora::Jugadora(){ 
    hp = 0;
    race =  " ";
    name = " ";
    mp = 0;
}

//constructor parametrizado
Jugadora::Jugadora(int nHp, std::string nRace, std::string nName, int nMp, LinkedList<Monstruo> monstruos) 
    : hp(nHp), race(nRace), name(nName), mp(nMp), monstruosDerrotados(monstruos) {
}

//destructor
Jugadora::~Jugadora(){
}

//getters y setters
int Jugadora::getHp(){
    return hp;
}

std::string Jugadora::getRace(){
    return race;
}

std::string Jugadora::getName(){
    return name;
}


int Jugadora::getMp(){
    return mp;
}

void Jugadora::setHp(int nHp){
    hp = nHp;
}

void Jugadora::setRace(std::string nRace){
    race = nRace;
}

void Jugadora::setName(std::string nName){
    name = nName;
}

void Jugadora::setMp(int nMp){
    mp = nMp;
}

//método imprimirLista
void Jugadora::mostrarInfoMonstruosDerrotados(){
    return monstruosDerrotados.imprimeLista();
    
}

//método insertaFinal
bool Jugadora::agregarMonstruo(Monstruo nMonstruo){
    return monstruosDerrotados.insertarFinal(nMonstruo);
}