/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 6b de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * mostrar arreglos de objetos
 *
 */
#include <iostream>

using namespace std;

#define MAX_SIZE 4

class Persona {
public:
    Persona() { cout << "Persona creada\n"; }
    ~Persona() { cout << "Persona " << nombre << " destruida\n"; }
    string getNombre() { return nombre; };
    void setNombre(string nombre) { this->nombre = nombre; };
private:
    string nombre;
};

int main() {
    string nombres[MAX_SIZE] = { "Juan", "Pedro", "Luis", "Karen" };
    Persona* ptr = new(nothrow) Persona[MAX_SIZE];

    if (!ptr) {
        cout << "Not enough memory\n";
        return 0;
    }

    for (unsigned int i = 0; i < MAX_SIZE; i++)
        ptr[i].setNombre(nombres[i]);

    delete [] ptr;
    ptr = nullptr;

    cout << "terminando programa\n";
    return 0;
}
