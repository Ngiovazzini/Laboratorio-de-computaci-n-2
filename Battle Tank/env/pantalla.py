import pygame
from clases import *
from dibujar import matriz,matriz_mapa

pygame.init()
#_______VARIABLES_________________
width=800
height=600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Battle Tank")
clock = pygame.time.Clock()
run=True
filas = width//32
columnas = height//32
tile_size=32
ancho_tiles = width // tile_size
alto_tiles = height // tile_size
pos_tank_x=15
pos_tank_y=0

#___________________________________________

#__________Objetos______________

player_tank=Tank(pos_tank_x,pos_tank_y,'sprits/Derecha.png',tile_size)
player_tank_group=pygame.sprite.Group()
player_tank_group.add(player_tank)
obstaculos=pygame.sprite.Group()
#_______________________________________________________

#________Funciones__________________
def cuadricula():
    for i in range(0,width):
        pygame.draw.line(screen, (255,255,255), (0,i*tile_size),(width,i*tile_size))
        #Empieza em x=0 y va iterando en i*32(baja de 32 en 32) termina en (x=800(ancho),y=linea*32)
        pygame.draw.line(screen, (255, 255, 255), (i*tile_size,0), (i * tile_size, height))
        #Empieza en (x=i*32) y termina en (x=i*32,600(altura)


def dibujar_escenario(matriz):

    # i = filas
    for i in range(len(matriz)):
        # j=columnas
        for j in range(len(matriz[i])):
            pos_x = j * tile_size
            pos_y = i * tile_size
            if (matriz[i][j] == 0):
              ladrillo=Brick(pos_x,pos_y,"sprits/Ladrillo_Rojo.png",tile_size)
              obstaculos.add(ladrillo)
#___________________________________________________

#______carga de imagenes en variables_______
try:
    tank_der=pygame.image.load("sprits/Derecha.png").convert_alpha()
    tank_der = pygame.transform.scale(tank_der, (tile_size, tile_size))
    tank_izq=pygame.image.load("sprits/Izquierda.png").convert_alpha()
    tank_izq=pygame.transform.scale(tank_izq, (tile_size, tile_size))
    tank_inf=pygame.image.load("sprits/Abajo.png").convert_alpha()
    tank_inf=pygame.transform.scale(tank_inf, (tile_size, tile_size))
    tank_sup=pygame.image.load("sprits/Arriba.png").convert_alpha()
    #ank_sup=pygame.transform.scale(tank_sup, (tile_size, tile_size))
    red_brick=pygame.image.load("sprits/Ladrillo_Rojo.png").convert_alpha()
    red_brick=pygame.transform.scale(red_brick, (tile_size, tile_size))
    white_brick = pygame.image.load("sprits/Ladrillo_Blanco.png").convert_alpha()
    white_brick = pygame.transform.scale(white_brick, (tile_size, tile_size))
                                                        #Reescala la imagen al tamaño deseado(title_size=64)
except(FileNotFoundError):
    print("Fallo la carga")
except(pygame.error):
    print("Error Pygame")

#_______________________________________

#_________BUCLE___________________
while run:
    #_____Corta el bucle si apretas la x roja_____
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run=False
        '''
        Como pygame registra todos los eventos en una cola de eventos ponemos todo lo que representa 
        un evento en un bucle for para que itere dentro de esa cola de eventos
        '''

    screen.fill((0,0,0))#Volves a llenar de negro el fondo en cada frame
    #cuadricula()#cuadricula para guiarnos en la pantalla
    dibujar_escenario(matriz_mapa)#EL escenario
    obstaculos.draw(screen)#Los ladrillos
    player_tank_group.draw(screen)#Eltanque player
    player_tank.update()
    pygame.display.update()#se dibuja
    clock.tick(60)#fps

pygame.quit()