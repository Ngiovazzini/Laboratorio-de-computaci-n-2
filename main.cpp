#include <iostream>
#include <string>
#include "Personaje.h"
#include "Heroe.h"
#include "Enemigo.h"

const int espada=10;
const int escudo=5;


int ranadom() {
    int aleatorio=rand()%1;
    return aleatorio;
}

int main() {
    int objetos[]={espada,escudo};

    int objetos_vacio[]={};
    std::string nombre_heroe;
    bool condicion=true;
    int danio=0;

    std::cout << "Ingrese el nombre del heroe \n";
    std::getline(std::cin, nombre_heroe);

    Heroe personaje_principal=Heroe(nombre_heroe,100,50,25,10,objetos);

    Enemigo personaje_enemigo=Enemigo("Frezzer",100,35,50,10,objetos);

    Enemigo BigBoss=Enemigo("Cell",100,65,43,15,objetos_vacio);

    std::cout << "Bienvenido al Juego de Batalla por turnos \n";
    std::cout << "El juego se ejecutara por linea de comandos \n";
    std::cout << "En la batalla vos representas al heroe y es quien ataca primero\n";
    while (personaje_principal.estado_vida()==false && personaje_enemigo.estado_vida()==false) {
        std::cout <<"El Heroe "<<personaje_principal.get_nombre()<<" Ataca";
        std::cout<<"La salud del Enemigo"<<personaje_enemigo.get_nombre()<<" es "<<personaje_enemigo.get_salud();
        std::cout<<"El Enemigo "<<personaje_enemigo.get_nombre()<<" Ataca";
        std::cout<<"La salud del Heroe"<<personaje_principal.get_nombre()<<" es "<<personaje_principal.get_salud();

    }
    personaje_principal.imrpimir_datos();
    std::cout<<"\n";
    personaje_enemigo .imrpimir_datos();
    std::cout<<"Batalla terminada";




    return 0;
}
