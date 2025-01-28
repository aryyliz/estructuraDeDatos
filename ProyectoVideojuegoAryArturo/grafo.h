#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "dobleListaLigadaT.h"
#include "stack.h"


template <typename T>
class Vertice{
public: 
    T dato;
    bool visitado = false;
    ListaDual<unsigned int> arista;
};

template <typename T>
class Grafo{
private: 
    Vertice<T> *vertices;
    unsigned int size;

    ListaDual<unsigned int> path;

public: 
    Grafo(){
        vertices = nullptr;
        size = 0;
    }

    ~Grafo(){
        borrarGrafo();
    }

    bool borrarVisitado(){
        for(unsigned int i = 0; i < size; i++){
            vertices[i].visitado = false;
        }
        return true;
    }

    bool crearGrafo(unsigned int nSize){
        if(nSize == 0 || vertices){
            return false;
        }

        vertices = new(std::nothrow) Vertice<T>[nSize];
        if(!vertices){
            return false;
        }
        size = nSize;
        return true;
    }

    bool insertarArista(unsigned int vert1, unsigned int vert2){
        if(!vertices){
            return false;
        }

        if(vert1 >= size || vert2 >= size){
            return false;
        }
        if(vertices[vert1].arista.buscar(vert2)){
            return false;
        }
        if(!vertices[vert1].arista.insertaFinal(vert2)){
            return false;
        }
        return true;
    }

    bool eliminaArista(unsigned int vert1, unsigned int vert2){
        if(!vertices){
            return false;
        }

        if(vert1 >= size || vert2 >= size){
            return false;
        }
        if(vertices[vert1].arista.busqueda(vert2)){
            return false;
        }
        if(!vertices[vert1].arista.borrarElemento(vert2)){
            return true;
        }
        return false;
    }

    void borrarGrafo(){
        if(vertices){
            delete [] vertices;
            vertices = nullptr;
            size = 0;
        }
    }

    bool cargarArchivo(const std::string& fileName){
        std::ifstream file(fileName);
        std::string line;
        unsigned int nSize = 0, vertice = 0;

        if(!file.is_open()) {
            std::cerr << "Error al abrir el archivo: " << fileName << std::endl; // Cambié 'csv' por 'fileName'
            return false;
        }

        // header (salta a la primera línea)
        if(!getline(file, line)) {
            std::cerr << "El archivo no tiene primera línea" << std::endl;
            file.close();
            return false;
        }

        if(line != "Grafo"){
            file.close();
            return false;
        }

        if(!getline(file, line)){
            std::cerr << "El grafo no tiene tamaño" << std::endl;
            file.close();
            return false;
        }

        if(!isValidNumber(line)){
            std::cerr << "El tamaño del grafo no es numério" << std::endl;
            file.close();
            return false;
        }

        nSize = stoi(line);

        if(nSize <= 0){
            std::cerr << "El tamaño del grafo es incorrecto" << std::endl;
            file.close();
            return false;
        }

        borrarGrafo();

        if(!crearGrafo(nSize)){
            std:: cerr << "No se pudo crear el grafo" << std::endl;
            file.close();
            return false;        
        }

        for(vertice = 0; vertice < nSize; vertice++){
            if(!getline(file, line)){
                std::cerr << "No hay arista" << std::endl;
                file.close();
                return false;
            }

            if(line.length()){
                std::stringstream ss(line);
                std::string cell;
                while(getline(ss, cell,' ')){
                    int fin = 0;
                    if(!isValidNumber(cell)){
                        file.close();
                        return false;
                    }

                    fin = stoi(cell);
                    if(!insertarArista(vertice, fin)){
                        file.close();
                        return false;
                    }
                }
            }
        }

        file.close();
        return true;
    }

    bool guardarArchivo(const std::string& fileName){
        std::ofstream file;

        if(!size){
            return false;
        }

        file.open(fileName, std::ios::out);
        if(!file.is_open()){
            std::cerr << "Error al guardar el archivo: " << fileName << std::endl;
            return false;
        }

        //El encabezado es una palabra
        file << "Grafo\n";
        //Cantidad de vértices
        file << size << "\n";

        //lista a agregar de arista
        for(unsigned int i = 0; i < size; i++){
            ListaDual<unsigned int>::iterator j(nullptr);
            for(j = vertices[i].arista.begin(); j != vertices[i].arista.end(); ++j){
                file << *j << " ";
            }
            file << "\n";
        }

        file.close();

        return true;
    }

    void imprimirGrafo(){
        for(unsigned int i = 0; i < size; i++){
            std::cout << "[" << i << "] " << vertices[i].dato << ": ";
            vertices[i].arista.imprime();
        }
    }

    void DFSrecursivo(unsigned int vertice){ //por profundidad
        vertices[vertice].visitado = true;
        std::cout << vertice << " ";
        ListaDual<unsigned int>::iterator i(nullptr);
        for(i = vertices[vertice].arista.begin(); i != vertices[vertice].arista.end(); ++i){
            if(!vertices[*i].visitado){
                DFSrecursivo(*i);
            }
        }
    }

    bool BFS(unsigned int verticeDeInicio){ //por amplitud
        Queue<unsigned int> queue;

        if(!size || verticeDeInicio >= size){
            return false;
        }

        borrarVisitado();

        std::cout << "BFS(" << verticeDeInicio << "): ";

        if(!queue.enqueue(verticeDeInicio)){
            return false;
        }

        vertices[verticeDeInicio].visitado = true;

        while(!queue.queueVacia()){
            unsigned int vertice = *queue.verFrente();

            std::cout << vertice << " ";
            queue.dequeue();

            for(auto arista : vertices[vertice].arista){ //por cada arista de ...
                if(!vertices[arista].visitado){
                    if(!queue.enqueue(arista)){
                        return false;
                    }
                    vertices[arista].visitado = true;
                }
            }
        }

        std::cout << "\n";
        return true;

    }

    /*bool dijkstra(unsigned int verticeDeInicio) {
        if (size == 0 || verticeDeInicio >= size){
            return false;    
        }

        inicializaDijkstra(verticeDeInicio);
        distancia[verticeDeInicio] = 0;

        std::cout << "Dijkstra(" << verticeDeInicio << "):\n";

        for (unsigned int i = 0; i < size - 1; ++i) {
            unsigned int verticeActual = getNextVertexDijkstra();

            if (verticeActual != UINT_MAX) {
                vertices[verticeActual].visitado = true;

                for (auto arista : vertices[verticeActual].edges) {
                    unsigned int pesoArista = 1; // Aquí es 1, pero se toma el peso real de la arista

                    if (!vertices[arista].visitado) {
                        unsigned int nuevaDistancia = distancia[verticeActual] + pesoArista;

                        if (nuevaDistancia < distancia[arista]) {
                            distancia[arista] = nuevaDistancia;
                            prev[arista] = verticeActual;
                        }
                    }
                }
            }
        }
        printDijkstraResults(verticeDeInicio);
        return true;
    }

    void inicializaDijkstra(unsigned int verticeDeInicio) {
        borrarVisitado();
        for (unsigned int i = 0; i < size; i++) {
            distancia[i] = UINT_MAX;
        }
    }

    unsigned int getNextVertexDijkstra() {
        unsigned int minDistancia = UINT_MAX;
        unsigned int verticeSiguiente = UINT_MAX;

        for (unsigned int i = 0; i < size; i++) {
            if (!vertices[i].visitado && distancia[i] < minDistancia) {
                minDistancia = distancia[i];
                verticeSiguiente = i;
            }
        }

        return verticeSiguiente;
    } */

    bool BFSPath(unsigned int verticeDeInicio, unsigned int verticeFinal, ListaDual<unsigned int>& path){
        if(!size || verticeDeInicio >= size || verticeFinal >= size){
            return false;
        }

        borrarVisitado();

        unsigned int* prev = new(std::nothrow) unsigned int[size];
        if(!prev){
            return false;
        }

        for(unsigned int i = 0; i < size; i++){
            prev[i] = UINT_MAX;
        }

        Queue<unsigned int> queue;

        if(!queue.enqueue(verticeDeInicio)){
            delete[] prev;
            return false;
        }

        vertices[verticeDeInicio].visitado = true;

        while(!queue.queueVacia()){
            unsigned int verticeActual = *queue.verFrente();

            if(!queue.dequeue()){
                delete[] prev;
                return false;
            }

            for(auto conexion : vertices[verticeActual].arista){
                if(!vertices[conexion].visitado){
                    if(!queue.enqueue(conexion)){
                        delete[] prev;
                        return false;
                    }

                    vertices[conexion].visitado = true;
                    prev[conexion] = verticeActual;

                    if(conexion == verticeFinal){
                        Stack<unsigned int> stack;
                        unsigned int actual = verticeFinal;

                        while(actual != UINT_MAX){
                            if(!stack.push(actual)){
                                delete[] prev;
                                return false;
                            }

                            actual = prev[actual];
                        }

                        while(!stack.isEmpty()){
                            if(!path.insertaFinal(*stack.getTop())){
                                delete[] prev;
                                return false;
                            }

                            if(!stack.pop()){
                                delete[] prev;
                                return false;
                            }
                        }

                        delete[] prev;
                        return true;
                    }
                }
            }
        }

        delete[] prev;
        return false;

    }

    bool setVertice(const unsigned int vertice, T dato){
        if(!size || vertice >= size){
            return false;
        }

        vertices[vertice].dato = dato;
        return true;
    }
    
    unsigned int getSize(){
        return this->size;
    }

    bool isValidNumber(const std::string &stg){
        for(int i = 0; i < stg.length(); i++){
            if(!isdigit(stg[i])){
                return false;
            }
        }
        return true;
    }

    T* verticeInfo(unsigned int index){
        if(index >= size || !vertices){
            return nullptr;
        }

        return &vertices[index].dato;
    }
};