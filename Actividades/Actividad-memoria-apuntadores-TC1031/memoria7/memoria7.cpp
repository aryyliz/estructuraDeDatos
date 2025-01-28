/*
 * Ejemplos secuenciales de uso de memoria
 *
 * Ejemplo 7 de uso de memoria dinámica
 *
 * Este ejemplo tiene la intención de 
 * mostrar el uso INCORRECTO del apuntador
 * después de haber liberado la memoria
 * con delete.
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

    if(!ptr) {
        cout << "Not enough memory\n";
        return nullptr;
    }

    ptr->nombre = "Juan";

    return ptr;
}

int main() {
    Persona* ptr = nullptr;

    ptr = crearPersona();
    
    // Hacemos uso incorrecto del apuntador ya que:
    // 1) No verificamos si existe antes de 
    //      llamar delete para regresar la memoria
    // 2) Accedemos a un atributo ya que destruímos el objeto
    delete ptr;
    cout << "(main) Nombre: " << ptr->nombre << "\n";

    cout << "terminando programa\n";
    return 0;
}
