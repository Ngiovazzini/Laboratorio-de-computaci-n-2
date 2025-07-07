import pygame
import pygame as py

class Tank(py.sprite.Sprite):
    def __init__(self, x, y,ruta,tile_size):
        super().__init__()

        image_s_escalar = pygame.image.load(ruta).convert()
        self.image = py.transform.scale(image_s_escalar,(tile_size,tile_size) )
        self.rect = self.image.get_rect()
        self.rect.center=(x,y)
