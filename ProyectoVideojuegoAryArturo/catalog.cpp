#include "catalog.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>

ArbolBinario<Monstruo> miCatalogo;

Catalog::Catalog() : miCatalogo(){
    srand(static_cast<unsigned int>(time(0)));
}

Catalog::~Catalog(){
}

bool Catalog::loadFromCSV(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    unsigned int size = 0;

    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo: " << fileName << std::endl; // Cambié 'csv' por 'fileName'
        return false;
    }

    // header (salta a la primera línea)
    if (!getline(file, line)) {
        std::cerr << "El archivo no tiene primera línea" << std::endl;
        file.close();
        return false;
    }

    std::cout << "Cargando archivo: " << fileName << std::endl; // Cambié 'csv' por 'fileName'

    while (getline(file, line)) {
        Monstruo nMonstruo;
        std::stringstream ss(line);
        std::string cell;
        int campo = 0, errores = 0;

        while (getline(ss, cell, ',')) {
            if (cell.empty())
                errores++;

            switch (campo) {
                case 0:
                    nMonstruo.setName(cell);
                    break;
                case 1:
                    nMonstruo.setCr(stof(cell));
                    break;
                case 2:
                    nMonstruo.setType(cell);
                    break;
                case 3:
                    nMonstruo.setSize(cell);
                    break;
                case 4:
                    nMonstruo.setAc(stoi(cell));
                    break;
                case 5:
                    nMonstruo.setHp(stoi(cell));
                    break;
                case 6:
                    nMonstruo.setAlign(cell);
                    break;
                default:
                    errores++;
                    break;
            }
            campo++;
        }

        if (errores) {
            std::cerr << "Error en la línea: " << line << std::endl;
            file.close();
            return false;
        }

        if(!miCatalogo.inserta(nMonstruo)){
            file.close();
            return false;
        }

    }

    file.close();
    return true;
}

Monstruo* Catalog::randomMonstruo() {
    int totalMonstruos = miCatalogo.getSize(); 
    
    if (totalMonstruos == 0) {
        std::cerr << "Catálogo vacío" << std::endl;
        return nullptr;
    }
    int seleccionMonstruo = rand() % totalMonstruos + 1;
    Monstruo* monstruoSeleccionado = miCatalogo.busquedaInOrder(seleccionMonstruo);
    return monstruoSeleccionado;
}
