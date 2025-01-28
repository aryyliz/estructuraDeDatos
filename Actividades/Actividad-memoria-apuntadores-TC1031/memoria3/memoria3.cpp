/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 3 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * demostrar como se comportan los
 * constructores y destructores de las
 * clases con new y delete
 * 
 * La guía de estilo no se sigue con las declaraciones
 * para mantener la brevedad y simpleza en los ejemplos
 * 
 */

#include <iostream>

using namespace std;

// Definimos una clase de manera breve en el main como ejemplo
class Persona {
public:
    Persona() { cout << "Persona creada\n"; }
    ~Persona() { cout << "Persona destruida\n"; }
};

int main() {
    Persona* ptr = nullptr;

    ptr = new(nothrow) Persona();
    if (!ptr) {
        cout << "Not enough memory\n";
        return 0;
    }

    cout << "En el main, antes del delete\n";

    delete ptr;
    ptr = nullptr;

    return 0;
}
