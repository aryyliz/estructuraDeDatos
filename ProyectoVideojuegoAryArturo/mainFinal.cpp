#include <iostream>
#include "catalog.h"
#include "dungeon.h"

//Aryam Lizette Buendía Zavala A01659465
//José Arturo Pérez Aguilar A01665272


int main() {
    unsigned int inicio, fin;
    Catalog    miCatalogo;
    Dungeon     miDungeon;

    if(!miCatalogo.loadFromCSV("monsters.csv")) {
        std::cout << "No se pudo crear el catalogo" << std::endl;
        return 0;
    }

    std::cout << "Creando Dungeon..." << std::endl;
    if(!miDungeon.createDungeon("dungeon.txt")) {
        std::cout << "No se pudo crear el Dungeon" << std::endl;
        return 0;
    }

    for(unsigned int c = 0; c < miDungeon.getSize(); c ++) {
        Monstruo *pMonstruo = nullptr, copiaMonstruo;

        pMonstruo = miCatalogo.randomMonstruo();
        if(!pMonstruo) {
            std::cout << "No se pudo obtener un monstruo del catalogo" << std::endl;
            return 0;
        }

        copiaMonstruo = *pMonstruo;
        if(!miDungeon.createRoom(c, copiaMonstruo)) {
            std::cout << "No se pudo insertar cuarto con monstruo al calabozo" << std::endl;
            return 0;
        }
    }

    miDungeon.imprimir();

    std::cout << "Elije una ruta:\n";
    do {
        std::cout << "Dame el cuarto inicial: ";
        std::cin >> inicio;
        std::cout << "Dame el cuarto final: ";
        std::cin >> fin;
    } while (fin > miDungeon.getSize() || inicio == fin);

    if(!miDungeon.trazaRuta(inicio, fin)) {
        std::cout << "No existe ruta de " << inicio << " a " << fin << "\n";
        return 0;
    }

    miDungeon.imprimirRuta();

    do {
        Cuarto *actual = nullptr;

        actual = miDungeon.cuartoActualRuta();
        if(actual) {
            std::cout << "Entrando a " << *actual << "\n";
        }
    } while (miDungeon.avanzaRuta());

    return 0;
}