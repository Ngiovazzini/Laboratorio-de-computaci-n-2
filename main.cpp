#include <iostream>
#include <string>
#include <vector>

const int espada=10;
const int escudo=-5;
const int acha=15;
const int casco=-3;

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
    void atacar() {

    }
public:
    void recibir_dano() {

    }
public:
    void subir_nivel() {

    }
};

class Heroe: public Personaje {
public:
    Heroe(std:: string nombre,int salud,int ataque,int defensa,int nivel,int objeto[2]) : Personaje(nombre,salud,ataque,defensa,nivel,objeto) {

}
};

class Enemigo: public Personaje{
public:
    Enemigo(std:: string nombre,int salud,int ataque,int defensa,int nivel,int objeto[2]) : Personaje(nombre,salud,ataque,defensa,nivel,objeto) {
    }
};

int main() {
int objetos_heroe[]={espada,escudo};
int objetos_enemigo[]={acha,casco};
int objetos_vacio[]={};
std::string nombre_heroe;

std::cout << "Ingrese el nombre del heroe \n";
std::getline(std::cin, nombre_heroe);

Heroe personaje_principal=Heroe(nombre_heroe,100,50,25,10,objetos_heroe);

Enemigo personaje_enemigo=Enemigo("Frezzer",100,35,50,10,objetos_enemigo);

Enemigo BigBoss=Enemigo("Cell",100,65,43,15,objetos_vacio);


    return 0;
}
