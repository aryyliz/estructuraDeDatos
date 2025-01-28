#pragma once
#include <iostream>
#include "monstruo.h"
#include "arbolbinarioT.h"

class Catalog{
public: 
    Catalog();
    ~Catalog();

    bool loadFromCSV(const std::string& fileName);
    Monstruo* randomMonstruo();

private: 
    ArbolBinario<Monstruo> miCatalogo;
};