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

except FileNotFoundError:
    print("NO SE ENCONTRO EL ARCHIVO")
except pygame.error:
    print("ERROR PYGAME")

#-------Diccionario imagenes----
imagenes={
    "Ship":ship
}
#------Objetos-------
nave=Ship((width/2,height),imagenes)
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
    nave_group.update()
    py.display.flip()
    clock.tick(60)
py.quit()
