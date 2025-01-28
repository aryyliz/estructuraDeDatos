/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 8 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * mostrar el uso INCORRECTO de delete
 * al llamarlo dos veces sobre el mismo
 * apuntador.
 * Al ejecutarse, nunca llega a la línea
 * a imprimir "terminando programa"
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

    if(!ptr)
        return 0;

    cout << "(main) Nombre: " << ptr->nombre << "\n";
    // Aca la liberamos correctamente...
    delete ptr;
    // Y acá cometemos el error al liberar por segunda vez
    delete ptr;
    cout << "terminando programa\n";

    return 0;
}
