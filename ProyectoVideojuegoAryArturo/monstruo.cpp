#include "monstruo.h"

//constructor inicializador
Monstruo::Monstruo(){ 
    name = " ";
    cr = 0.0;
    type = " ";
    size = " ";
    ac = 0;
    hp = 0;
    align = " ";
}

//constructor parametrizado
Monstruo::Monstruo(std::string name, double cr, std::string type, std::string size, int ac, int hp, std::string align)
    : name(name), cr(cr), type(type), size(size), ac(ac), hp(hp), align(align) {
}

//destructor
Monstruo::~Monstruo() {
}

//sobrecarga de operadores
std::ostream& operator<<(std::ostream& os, const Monstruo& monstruo){
        os << monstruo.name;
        return os;
}

//getters
std::string Monstruo::getName(){
    return name;
}

int Monstruo::getCr(){
    return cr;
}

std::string Monstruo::getType(){
    return type;
}

std::string Monstruo::getSize(){
    return size;
}

int Monstruo::getAc(){
    return ac;
}

int Monstruo::getHp(){
    return hp;
}

std::string Monstruo::getAlign(){
    return align;
}

//setters
void Monstruo::setName(std::string nName) {
    name = nName;
}

void Monstruo::setCr(double nCR) {
    cr = nCR;
}

void Monstruo::setType(std::string nType) {
    type = nType;
}

void Monstruo::setSize(std::string nSize) {
    size = nSize;
}

void Monstruo::setAc(int nAC) {
    ac = nAC;
}

void Monstruo::setHp(int nHP) {
    hp = nHP;
}

void Monstruo::setAlign(std::string nAlign) {
    align = nAlign;
}

//método para imprimir la información del Monstruo
void Monstruo::printCreatureData() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "cr: " << cr << std::endl;
    std::cout << "type: " << type << std::endl;
    std::cout << "size: " << size << std::endl;
    std::cout << "ac: " << ac << std::endl;
    std::cout << "hp: " << hp << std::endl;
    std::cout << "align: " << align << std::endl;
}