import pygame
import dibujar

pygame.init()

screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Batalla de Tanques")
clock = pygame.time.Clock()
run=True

while run:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run=False

    screen.fill((0,0,0))

    pygame.display.update()
    clock.tick(60)

pygame.quit()