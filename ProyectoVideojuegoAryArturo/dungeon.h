#pragma once
#include <iostream>
#include "cuarto.h"
#include "grafo.h"
#include "dobleListaLigadaT.h"

class Dungeon{
public:
    Dungeon();
    ~Dungeon();

    bool createRoom(unsigned int vertice, Monstruo& monstruo);
    bool createDungeon(const std::string &fileName);
    unsigned int getSize();
    void imprimir();
    void imprimirRuta();
    bool trazaRuta(unsigned int cuartoInicio, unsigned int cuartoFinal);
    bool avanzaRuta();
    Cuarto* cuartoActualRuta();


private:
    Grafo<Cuarto> cuartos;
    ListaDual<unsigned int> path;
    unsigned int cuartoActual;
};