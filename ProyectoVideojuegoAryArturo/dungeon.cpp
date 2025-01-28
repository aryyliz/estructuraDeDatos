#include "dungeon.h"

Dungeon::Dungeon() : cuartos() {}

Dungeon::~Dungeon() {
    cuartos.borrarGrafo();
}

bool Dungeon::createRoom(unsigned int vertice, Monstruo& monstruo) {
    Cuarto nuevo(monstruo);
    return cuartos.setVertice(vertice, nuevo);
}

bool Dungeon::createDungeon(const std::string &fileName){
    return cuartos.cargarArchivo(fileName);
}

unsigned int Dungeon::getSize(){
    return cuartos.getSize();
}

void Dungeon::imprimir(){
    cuartos.imprimirGrafo();
}

void Dungeon::imprimirRuta(){
    path.imprime();
}

bool Dungeon::trazaRuta(unsigned int inicio, unsigned int final){
    if(!cuartos.BFSPath(inicio, final, path)){
        std::cerr << "No se encuentra una ruta entre los cuartos" << std::endl;
        return false;
    }

    if(path.getSize() <= 0){
        return false;
    }

    this->cuartoActual = inicio;
    return true;
}

bool Dungeon::avanzaRuta(){
    if(path.getSize() == 0){
        return false;
    }

    auto iteradorPath = path.begin();

    while(iteradorPath != path.end() && *iteradorPath != cuartoActual){
        ++iteradorPath;
    }

    if(iteradorPath != path.end() && ++iteradorPath != path.end()){
        cuartoActual = *iteradorPath;
        return true;
    }

    return false;
}

Cuarto* Dungeon::cuartoActualRuta(){
    return cuartos.verticeInfo(cuartoActual);
}