/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 6 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * mostrar acceso a miembros
 *
 */
#include <iostream>

using namespace std;

class Persona {
public:
    Persona() { cout << "Persona creada\n"; }
    ~Persona() { cout << "Persona destruida\n"; }
    string getNombre() { return nombre; };
    void setNombre(string nombre) { this->nombre = nombre; };
private:
    string nombre;
};

int main() {
    Persona* ptr = new(nothrow) Persona();

    if (!ptr) {
        cout << "Not enough memory\n";
        return 0;
    }

    ptr->setNombre("Karen");
    cout << "Nombre: " << ptr->getNombre() << "\n";

    delete ptr;
    ptr = nullptr;

    cout << "terminando programa\n";
    return 0;
}
