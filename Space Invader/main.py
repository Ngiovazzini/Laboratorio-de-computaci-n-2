import pygame
import pygame as py
from clases import *
#-----Setup-------
py.init()
width=800
height=600
screen = py.display.set_mode((width, height))
clock = py.time.Clock()
run = True
tiled_size=32
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
except FileNotFoundError:
    print("NO SE ENCONTRO EL ARCHIVO")
except pygame.error:
    print("ERROR PYGAME")

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
    "Full":health_full
}
#------Objetos-------

vida=Health((50,50),imagenes)
vida_group = pygame.sprite.Group()
vida_group.add(vida)
#obstaculo=Obstaculo((width/2,150))
#obstaculo_group=pygame.sprite.Group()
#obstaculo_group.add(obstaculo)
nave=Ship((width/2,height),imagenes,vida)
nave_group = pygame.sprite.Group()
nave_group.add(nave)
#--------Bucle---------
while run:
    for event in py.event.get():
        if event.type == py.QUIT:
            run = False

    screen.fill((0, 0, 0))
    screen.blit(background,(0,0))
    screen.blit(planet, (300, 100))
    nave_group.draw(screen)
    vida_group.draw(screen)
    nave_group.update()
    py.display.flip()
    clock.tick(60)
py.quit()
