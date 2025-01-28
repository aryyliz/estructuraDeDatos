/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 5 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * mostrar el uso de -> con el apuntador
 * y sus atributos.
 */
#include <iostream>

using namespace std;

class Persona {
public:
    Persona() { cout << "Persona creada\n"; }
    ~Persona() { cout << "Persona destruida\n"; }

    string nombre;
};

Persona* crearPersona() {
    Persona* ptr = new(nothrow) Persona();

    if (!ptr) {
        cout << "Not enough memory\n";
        return nullptr;
    }

    ptr->nombre = "Juan";

    return ptr;
}

int main() {
    Persona* ptr = nullptr;

    ptr = crearPersona();

    if (ptr) {
        cout << "(main) Nombre: " << ptr->nombre << "\n";

        delete ptr;
        ptr = nullptr;
    }

    cout << "terminando programa\n";
    return 0;
}
