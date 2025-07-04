import pygame
import dibujar

pygame.init()
width=800
height=600
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Battle Tank")
clock = pygame.time.Clock()
run=True
filas = 800//32
columnas = 600//32
tile_size=64

def cuadricula():
    for i in range(0,13):
        pygame.draw.line(screen, (255,255,255), (0,i*tile_size),(width,i*tile_size))
        #Empieza em x=0 y va iterando en i*32(baja de 32 en 32) termina en (x=800(ancho),y=linea*32)
        pygame.draw.line(screen, (255, 255, 255), (i*tile_size,0), (i * tile_size, height))
        #Empieza en (x=i*32) y termina en (x=i*32,600(altura)

try:
    tank_der=pygame.image.load("sprits/Derecha.png").convert_alpha()
    #tank_der = pygame.transform.scale(tank_der, (width, height))
    tank_izq=pygame.image.load("sprits/Izquierda.png").convert_alpha()
    tank_izq=pygame.transform.scale(tank_izq, (width, height))
    tank_inf=pygame.image.load("sprits/Abajo.png").convert_alpha()
    tank_inf=pygame.transform.scale(tank_inf, (width, height))
    tank_sup=pygame.image.load("sprits/Arriba.png").convert_alpha()
    #tank_sup=pygame.transform.scale(tank_sup, (width, height))
    red_brick=pygame.image.load("sprits/Ladrillo_Rojo.png.png").convert_alpha()
    red_brick=pygame.transform.scale(red_brick, (width, height))
    white_brick = pygame.image.load("sprits/Ladrillo_Blanco.png").convert_alpha()
    white_brick = pygame.transform.scale(white_brick, (width, height))
except(FileNotFoundError):
    print("Fallo la carga")
except(pygame.error):
    print("Error Pygame")

while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run=False

    screen.fill((0,0,0))
    cuadricula()
    pygame.display.update()
    clock.tick(60)

pygame.quit()