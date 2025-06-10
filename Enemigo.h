#include "Personaje.h"

#ifndef ENEMIGO_H
#define ENEMIGO_H



class Enemigo: public Personaje{
public:
    Enemigo(std:: string nombre,int salud,int ataque,int defensa,int nivel,int objeto[2]) : Personaje(nombre,salud,ataque,defensa,nivel,objeto) {
    }
};



#endif //ENEMIGO_H
