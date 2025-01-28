#pragma once
#include <iostream>
#include "monstruo.h"
#include "catalog.h"

class Cuarto{
public: 
    Cuarto();
    Cuarto(Monstruo& monstruo);
    ~Cuarto();

    //sobrecarga
    friend std::ostream& operator<<(std::ostream& os, Cuarto& Cuarto);

private:
    Monstruo cuartoMonstruo;
};
