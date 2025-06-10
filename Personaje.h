#include <iostream>
#include <string>

#ifndef PERSONAJE_H
#define PERSONAJE_H



class Personaje{
private:
    std:: string nombre;
    int salud, ataque, defensa, nivel;
    int objeto[2]={};
public:
    Personaje(std:: string nombre,int salud,int ataque,int defensa,int nivel,int objeto[2]) {
        this->nombre=nombre;
        this->salud=salud;
        this->ataque=ataque;
        this->defensa=defensa;
        this->nivel=nivel;
        this->objeto[0]=objeto[0];
        this->objeto[1]=objeto[1];
    }
public:
    void imrpimir_datos() {
        std::cout <<"Nombre: "<< nombre<<"\n";
        std::cout << "Salud: "<<salud<<"\n";
        std::cout <<"Ataque: "<<ataque<<"\n";
        std::cout <<"Defensa: "<<defensa<<"\n";
        std::cout <<"Nivel:"<<nivel<<"\n";
        std::cout <<"Arma de ataque: " <<objeto[0]<<"\n";
        std::cout <<"Arma de defensa: "<< objeto[1]<<"\n";
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
     int atacar(int *danio) {
         ataque+=objeto[0];
         defensa+=objeto[1];
        *danio=ataque-defensa;
    }
public:
    void recibir_danio(int *danio) {
        salud=salud-*danio;
        salud-=*danio;

    }
public:
    void subir_nivel() {
        nivel+=10;
    }

public:
    bool estado_vida() {
        if (salud>=0)  return true;
    }
};


#endif //PERSONAJE_H
