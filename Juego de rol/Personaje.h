#include <iostream>
#include <string>
#include "Objeto.h"
#ifndef PERSONAJE_H
#define PERSONAJE_H



class Personaje{
public:
    std:: string nombre;
    int salud, ataque, defensa, nivel;
    Objeto objetoAtaque;
    Objeto objetoDefensa;
public:
    Personaje(std:: string nombre,int salud,int ataque,int defensa,int nivel,Objeto objetoAtaque,Objeto objetoDefensa): nombre(nombre), salud(salud), ataque(ataque), defensa(defensa), nivel(nivel),
      objetoAtaque(objetoAtaque), objetoDefensa(objetoDefensa) {
        this->nombre=nombre;
        this->salud=salud;
        this->ataque=ataque;
        this->defensa=defensa;
        this->nivel=nivel;
        this->objetoAtaque=objetoAtaque;
        this->objetoDefensa=objetoDefensa;
    }
public:
    virtual void imrpimir_datos() {
        std::cout <<"Nombre: "<< nombre<<"\n";
        std::cout << "Salud: "<<salud<<"\n";
        std::cout <<"Ataque: "<<ataque<<"\n";
        std::cout <<"Defensa: "<<defensa<<"\n";
        std::cout <<"Nivel:"<<nivel<<"\n";
        std::cout <<"Arma de ataque: " <<objetoAtaque.valor<<"\n";
        std::cout <<"Arma de defensa: "<< objetoDefensa.valor<<"\n";
    }

public:
    std::string get_nombre() {
       return nombre;
    }

public:
    int get_salud() {
        return salud;
    }

public:
     void atacar(Personaje &enemigo) {
        int danio=ataque-enemigo.defensa;
        enemigo.recibir_danio(danio);
    }
public:
    void recibir_danio(int& danio) {
        salud-=danio;

    }

public:
    void subir_nivel() {
        nivel+=10;
        ataque+=5;
        defensa+=5;
        salud+=8;
        std::cout <<"Felicidades subiste de nivel"<<"\n";
        imrpimir_datos();
    }

public:
    bool estado_vida() {
        if (salud>0) {
            return true;
        }
        else{ return false;}
    }
public:
    virtual void turno(Personaje& heroe ,Personaje& enemigo) {

            int opcion;
            std::cout <<"Elija la opcion deseada"<< std::endl;
            std::cout <<"1-Desea atacar usando un objeto?"<< std::endl;
            std::cout <<"2-Desea aumentar su defensa con un objeto?"<< std::endl;
            std::cout <<"3-Desea atacar sin ningun objeto?"<< std::endl;
            std::cin >> opcion;
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
            enemigo.imrpimir_datos();
            std::cout<<"\n";
            heroe.imrpimir_datos();


    }

};


#endif //PERSONAJE_H
