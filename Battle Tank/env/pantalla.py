import pygame
from dibujar import matriz

pygame.init()
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
            if (matriz[i][j] == 1):
                screen.blit(red_brick, (pos_x, pos_y))
            elif (matriz[i][j] == 2):
                screen.blit(tank_izq, (pos_x, pos_y))
            elif (matriz[i][j] == 3):
                screen.blit(tank_der, (pos_x, pos_y))


#carga de imagenes en variables
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
print("Filas:",filas)
print("Columnas:",columnas)
print("Tile Size:",tile_size)
print("Ancho Tiles:",ancho_tiles)
print("Alto Tiles:",alto_tiles)

while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run=False

    screen.fill((0,0,0))
    cuadricula()

    dibujar_escenario(matriz)
    pygame.display.update()
    clock.tick(60)

pygame.quit()