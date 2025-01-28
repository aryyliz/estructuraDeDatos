/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 9 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * mostrar como el asignar nullptr al inicio
 * y la practica de revisar el apuntador 
 * antes de usarlo y liberarlo ayudan
 * a evitar errores.
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
    Persona* p = new(nothrow) Persona();

    if(!p) {
        cout << "Not enough memory" << endl;
        return nullptr;
    }

    p->nombre = "Juan";

    return p;
}

int main() {
    Persona* p = nullptr;

    p = crearPersona();
    
    // revisamos si si tenemos un objeto válido
    if(p) {
        cout << "(main) Nombre: " << p->nombre << endl;
    }
    if(p) {
        delete p;
        p = nullptr;
    }
    // si revisamos p, no se liberará de nuevo
    if(p) {
        delete p;
        p = nullptr;
    }
    cout << "terminando programa" << endl;
    return 0;
}
