import pygame
import pygame as py

class Tank(py.sprite.Sprite):
    def __init__(self, x, y,ruta,tile_size):
        super().__init__()

        image_s_escalar = pygame.image.load(ruta).convert()
        self.image = py.transform.scale(image_s_escalar,(tile_size,tile_size) )
        self.rect = self.image.get_rect()
        self.rect.topleft = (x, y)

    def update(self):
        teclas=py.key.get_pressed() #esto devuelve un true si una tecla es presionada
        if teclas[py.K_UP]:
            self.rect.move_ip(0,-2)
        if teclas[py.K_DOWN]:
            self.rect.move_ip(0,2)
        if teclas[py.K_LEFT]:
            self.rect.move_ip(-2,0)
        if teclas[py.K_RIGHT]:
            self.rect.move_ip(2,0)
