#pragma once
#include <iostream>

class Monstruo {
public:
    Monstruo();
    Monstruo(std::string name, double cr, std::string type, std::string size, int ac, int hp, std::string align);
    ~Monstruo();
    friend std::ostream& operator<<(std::ostream& os, const Monstruo& monstruo);

    //getters
    std::string getName();
    int getCr();
    std::string getType();
    std::string getSize();
    int getAc();
    int getHp();
    std::string getAlign();

    //setters
    void setName(std::string nName);
    void setCr(double nCR);
    void setType(std::string nType);
    void setSize(std::string nSize);
    void setAc(int nAC);
    void setHp(int nHP);
    void setAlign(std::string nAlign);

    //sobrecarga para que el arbol compare los elementos y los ordene
    bool operator<(const Monstruo& variable) const{
        return this->name < variable.name;
    }
    bool operator>(const Monstruo& variable) const{
        return this->name > variable.name;
    }

    void printCreatureData();
    
private:
    std::string name;
    double cr;
    std::string type;
    std::string size;
    int ac;
    int hp;
    std::string align;
};