#include "Personaje.h"
#include <string>
#include <iostream>//
#include <chrono>
#include <thread>
// Created by Usuario on 21/06/2025.
//

#ifndef JEFE_H
#define JEFE_H



class Jefe: public Personaje{
public:
    Jefe(std:: string nombre,int salud,int ataque,int defensa,int nivel,Objeto objetoAtaque,Objeto objetoDefensa) :
        Personaje(nombre,salud,ataque,defensa,nivel,objetoAtaque,objetoDefensa) {
    }
public:
    void imrpimir_datos() override{
        std::cout <<"Nombre: "<< nombre<<"\n";
        std::cout << "Salud: "<<salud<<"\n";
        std::cout <<"Ataque: "<<ataque<<"\n";
        std::cout <<"Defensa: "<<defensa<<"\n";
        std::cout <<"Nivel:"<<nivel<<"\n";
        std::cout <<"Posion de Vida: "<< objetoAtaque.valor<<"\n";
        std::cout <<"Posion de Defensa: "<< objetoDefensa.valor<<"\n";
    }
public:
    void turno(Personaje &heroe, Personaje &enemigo) override {
        int opcion;
        std::cout <<"Elija la opcion deseada"<< std::endl;
        std::cout <<"1-Aumentar su salud usando una posion"<< std::endl;
        std::cout <<"2-Aumentar su defensa usando una posion"<< std::endl;
        std::cout <<"3-Atacar"<< std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        opcion=1+ rand()%3;
        std::cout<<"Opcion elegida por el CPU "<<opcion<<"\n";
        switch (opcion) {
            case 1:
                if (heroe.objetoAtaque.uso()==false) {
                    heroe.salud+=heroe.objetoAtaque.valor;
                    break;
                }else{break;}

            case 2:if (heroe.objetoDefensa.uso()==false) {
                heroe.defensa+=heroe.objetoDefensa.valor;
                break;
            }else{break;}


            case 3: heroe.atacar(enemigo);
                break;
        }
        std::cout<<"----------------------------\n";
        enemigo.imrpimir_datos();
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout<<"----------------------\n";
        heroe.imrpimir_datos();
        std::cout<<"----------------------------\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        //Detengo la ejecucion si no no se ve nada

    }
};



#endif //JEFE_H
