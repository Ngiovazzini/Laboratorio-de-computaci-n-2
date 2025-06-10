#include "Personaje.h"

#ifndef HEROE_H
#define HEROE_H



class Heroe: public Personaje {
public:
    Heroe(std:: string nombre,int salud,int ataque,int defensa,int nivel,int objeto[2]) : Personaje(nombre,salud,ataque,defensa,nivel,objeto) {

    }
};

#endif //HEROE_H
