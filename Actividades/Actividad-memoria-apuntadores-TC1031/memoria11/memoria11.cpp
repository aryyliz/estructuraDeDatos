/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 11 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * mostrar el uso INCORRECTO de delete
 * al utilizarlo sobre memoria no asignada
 * por new, en este caso un objeto en el
 * stack de una función.
 */
 #include <iostream>

using namespace std;

class Persona {
public:
    Persona() { cout << "Persona creada\n"; }
    ~Persona() { cout << "Persona destruida\n"; }

    string nombre;
};

// Funcion incorrecta que regresa
// el apuntador a un objeto local,
// que ya fue destruído al terminar
// su marco de referencia en el stack.
Persona* crearPersona() {
    Persona p;
    Persona* ptr = &p;

    p.nombre = "Juan";

    return ptr;
}

int main() {
    Persona* ptr = nullptr;

    ptr = crearPersona();
    
    if(ptr) {
        cout << "(main) Nombre: " << ptr->nombre << endl;
    }
    if(ptr) {
        delete ptr;
        ptr = nullptr;
    }
    cout << "terminando programa" << endl;
    return 0;
}
