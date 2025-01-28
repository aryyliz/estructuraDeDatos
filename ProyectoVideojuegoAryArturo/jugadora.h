#pragma once
#include <iostream>
#include "monstruo.h"
#include "listaLigadaT.h"

class Jugadora{
public:
    Jugadora();
    Jugadora(int hp, std::string race, std::string name, int mp, LinkedList<Monstruo> monstruosDerrotados);
    ~Jugadora();

    //getters y setters
    int getHp();
    std::string getRace();
    std::string getName();
    int getMp();

    void setHp(int nhp);
    void setRace(std::string nRace);
    void setName(std::string nName);
    void setMp(int nMp);

    void mostrarInfoMonstruosDerrotados();
    bool agregarMonstruo(Monstruo nMonstruo);

private:
    int hp;
    std::string race;
    std::string name;
    int mp;
    LinkedList<Monstruo> monstruosDerrotados;  
};