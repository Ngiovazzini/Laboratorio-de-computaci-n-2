#include <iostream>
#include <string>
#include "Personaje.h"
#include "Objeto.h"
#include "Jefe.h"
#include "Enemigo.h"
#include <chrono>
#include <thread>

void saludo() {
    std::cout << "########################" << std::endl;
    std::cout << "Bienvenido a la batalla por turnos" << std::endl;
    std::cout << "Los turnos seras escogidos aleatoriamente" << std::endl;
    std::cout << "Cada personaje tiene dos objetos consumibles de un solo uso" << std::endl;
    std::cout << "El primero que se queda sin vida pierde" << std::endl;
    std::cout << "Suerte" << std::endl;
    std::cout << "#######################" << std::endl;
}


int main() {
    //VARIABLES E INSTANCIAS
    Objeto escudo=Objeto("Escudo","Defensa",15,0);
    Objeto espada=Objeto("Espada","Ataque",10,0);
    Objeto casco=Objeto("Casco","Defensa",5,0);
    Objeto acha=Objeto("Acha","Ataque",18,0);
    Objeto posionVida=Objeto("Posion vida","Vida",5,0);
    Objeto posionDefenza=Objeto("Posion defensa","Defensa",8,0);
    std::string nombre_heroe;
    srand(time(0));
    int aleatorio=0;
/*-----------------------------------------------*/
    std::cout << "Ingrese el nombre del heroe \n";
    std::getline(std::cin, nombre_heroe);
/*-----------------CREACION DE PERSONAJES-------------*/
    Personaje heroe=Personaje(nombre_heroe,100,80,25,10,espada,escudo);

    Enemigo enemigo=Enemigo("Frezzer",100,35,30,10,acha,casco);

    Jefe BigBoss=Jefe("Cell",100,65,23,15,posionVida,posionDefenza);
/*---------------------------------------------------------*/
/*---------------Primera ronda-----------------------------*/
    saludo();
    aleatorio=1+rand()%2;
    std::cout<<"aleatorio: "<<aleatorio<<"\n";
    switch (aleatorio) {
        case 1:heroe.turno(heroe,enemigo);
            break;
        case 2:enemigo.turno(enemigo,heroe);
    }

//BUCLE PRINCIPAL
    do{
        if (aleatorio==1) {
            std::cout<<std::endl;
            enemigo.turno(enemigo,heroe);
            std::cout<<std::endl;
            heroe.turno(heroe,enemigo);
        }else {
            std::cout<<std::endl;
            heroe.turno(heroe,enemigo);
            std::cout<<std::endl;
            enemigo.turno(enemigo,heroe);
        }


    }while(heroe.estado_vida()==true && enemigo.estado_vida()==true);

    if (heroe.estado_vida()==true) {
        heroe.subir_nivel();
    }else{enemigo.subir_nivel();}
/*--------------------Suiguiente Batalla-----------------*/
    if (heroe.estado_vida()==true) {
        std::cout<<"-------------------------------------------------------------"<<std::endl;
        std::cout<<"Bienvenido a la siguiente batalla"<<std::endl;
        std::cout<<"Aca te vas a enfrentar a "<<BigBoss.nombre<<std::endl;
        std::cout<<"El ganador de la anterior batalla comienza la ronda"<<std::endl;
        std::cout<<"Suerte"<<std::endl;
        std::cout<<"--------------------------------------------------------------"<<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        do {
            heroe.turno(heroe,BigBoss);
            BigBoss.turno(BigBoss,heroe);
        }while(heroe.estado_vida()==true && BigBoss.estado_vida()==true);
        if (heroe.estado_vida()==true) {
            std::cout<<"***************************"<<std::endl;
            std::cout<<"Felicitaciones "<<heroe.nombre<<std::endl;
            std::cout<<"Sos el ganador"<<std::endl;
            std::cout<<"****************************"<<std::endl;
        }else {
            std::cout<<"///////////////////////////"<<std::endl;
            std::cout<<"Perdiste Mala, suerte"<<std::endl;
            std::cout<<"////////////////////////////"<<std::endl;
        }
    }
    return 0;
}
