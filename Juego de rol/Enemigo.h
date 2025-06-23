#include "Personaje.h"
#include <chrono>
#include <thread>
#ifndef ENEMIGO_H
#define ENEMIGO_H



class Enemigo: public Personaje{
public:
    Enemigo(std:: string nombre,int salud,int ataque,int defensa,int nivel,Objeto objetoAtaque,Objeto objetoDefensa) :
        Personaje(nombre,salud,ataque,defensa,nivel,objetoAtaque,objetoDefensa) {
    }
public:
    void turno(Personaje &heroe, Personaje &enemigo) override {
        int opcion;
        std::cout <<"Elija la opcion deseada"<< std::endl;
        std::cout <<"1-Atacar usando un objeto"<< std::endl;
        std::cout <<"2-Aumentar su defensa con un objeto"<< std::endl;
        std::cout <<"3-Atacar"<< std::endl;

        opcion=1+ rand()%3;
        std::cout<<"Opcion elegida por el CPU "<<opcion<<"\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        switch (opcion) {
            case 1:
                if (heroe.objetoAtaque.uso()==false) {
                    heroe.ataque+=heroe.objetoAtaque.valor;
                    heroe.atacar(enemigo);
                    heroe.ataque-=heroe.objetoAtaque.valor;
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
        std::cout<<"-----------------------------\n";
        heroe.imrpimir_datos();
        std::cout<<"----------------------------\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        //Detengo la ejecucion si no no se ve nada


    }
};



#endif //ENEMIGO_H
