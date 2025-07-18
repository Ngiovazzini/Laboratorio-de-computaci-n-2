import pygame
import pygame as py
import random
from clases import *
#-----Setup-------
py.init()
width=800
height=600
screen = py.display.set_mode((width, height))
clock = py.time.Clock()
run = True
tiled_size=32
lista_enemigos=[]
lista_invaders=["Invaders1","Invaders2","Invaders3","Invaders4"]

#------Imagenes-----
try:
    background = py.image.load("Sprites/Space-Background.jpg")
    planet=py.image.load("Sprites/Planet.png")
    ship=py.image.load("Sprites/Ship.png")
    health_0=py.image.load("Sprites/0.png")
    health_1=py.image.load("Sprites/1.png")
    health_2=py.image.load("Sprites/2.png")
    health_3=py.image.load("Sprites/3.png")
    health_4=py.image.load("Sprites/4.png")
    health_5=py.image.load("Sprites/5.png")
    health_6=py.image.load("Sprites/6.png")
    health_full=py.image.load("Sprites/Full.png")
    invaders1=py.image.load("Sprites/Invaders_1.png")
    invaders2=py.image.load("Sprites/Invaders_2.png")
    invaders3=py.image.load("Sprites/Invaders_3.png")
    invaders4=py.image.load("Sprites/Invaders_4.png")
except FileNotFoundError:
    print("NO SE ENCONTRO EL ARCHIVO")
except pygame.error:
    print("ERROR PYGAME")
#------Funciones------
def crear_enemigos(lista_enemigos,lista_invaders):
    for i in range(0,20):
        for j in range(0,6):
            ran=random.choice(lista_invaders)
            enemigo = ShipEnemy((i*42 ,j*42), imagenes, vida, ran)
            lista_enemigos.append(enemigo)

#-------Diccionario imagenes----
imagenes={
    "Ship":ship,
    "0":health_0,
    "1":health_1,
    "2":health_2,
    "3":health_3,
    "4":health_4,
    "5":health_5,
    "6":health_6,
    "Full":health_full,
    "Invaders1":invaders1,
    "Invaders2":invaders2,
    "Invaders3":invaders3,
    "Invaders4":invaders4
}

#------Objetos-------

vida=Health((50,500),imagenes)
vida_group = pygame.sprite.Group()
vida_group.add(vida)

nave=Ship((width/2,height),imagenes,vida)
nave_group = pygame.sprite.Group()
nave_group.add(nave)

#enemigo=ShipEnemy((100,100),imagenes,vida,"Invaders1")
crear_enemigos(lista_enemigos,lista_invaders)
enemigo_group=pygame.sprite.Group()
enemigo_group.add(lista_enemigos)
#--------Bucle---------
while run:
    for event in py.event.get():
        if event.type == py.QUIT:
            run = False

    screen.fill((0, 0, 0))
    screen.blit(background,(0,0))
    screen.blit(planet, (300, 100))

    nave_group.draw(screen)
    nave_group.update()
    enemigo_group.draw(screen)
    vida_group.draw(screen)
    py.display.flip()
    clock.tick(60)
py.quit()
