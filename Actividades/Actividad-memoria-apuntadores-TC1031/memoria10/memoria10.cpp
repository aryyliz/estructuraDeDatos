/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 10 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de
 * mostrar el uso INCORRECTO de new
 * al asignar dos objetos nuevos al
 * mismo apuntador.
 * Esto genera un memory leak, ya que
 * sobreescibimos la referencia al
 * primer objeto en el heap.
 */
#include <iostream>

using namespace std;

class Persona {
public:
    Persona() { cout << "Persona creada" << endl; }
    ~Persona() { cout << "Persona " << nombre << " destruida" << endl; }

    string nombre;
};

Persona* crearPersona(string nombre) {
    Persona* p = new(nothrow) Persona();

    if (!p) {
        cout << "Not enough memory" << endl;
        return nullptr;
    }

    p->nombre = nombre;

    return p;
}

int main() {
    Persona* p = nullptr;

    p = crearPersona("Juan");  // primera asignación
    p = crearPersona("Pedro");  // segunda asignación

    if (p) {
        cout << "(main) Nombre: " << p->nombre << endl;
    }
    if (p) {
        delete p;
        p = nullptr;
    }
    cout << "terminando programa" << endl;
    // Nunca se liberó la primera asignación, memoryleak
    return 0;
}
