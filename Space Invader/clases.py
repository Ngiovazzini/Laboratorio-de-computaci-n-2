import pygame
import pygame as py


class Ship(py.sprite.Sprite):
    def __init__(self,pos,imagenes_estado,vida):
        super().__init__()
        self.vida = vida
        self.imagenes = imagenes_estado
        self.estado="Ship"
        self.image = imagenes_estado[self.estado]
        self.rect = self.image.get_rect(midbottom=pos)
        self.velocidad=3
    def move(self):
        teclado = py.key.get_pressed()

        if teclado[py.K_RIGHT]:
            self.rect.x+=self.velocidad
        if teclado[py.K_LEFT]:
            self.rect.x-=self.velocidad

        if self.rect.right == 800:
            self.rect.right-=self.velocidad
        if self.rect.left == 0:
            self.rect.left+=self.velocidad

    def update(self):
        self.move()
'''
class Obstaculo(py.sprite.Sprite,imagenes):
    def __init__(self,pos):
        super().__init__()
        
        self.image = imagenes
        self.rect = self.image.get_rect(midbottom=pos)
    def update(self):
        pass
'''
class Health(py.sprite.Sprite):
    def __init__(self,pos,imagenes_estado):
        super().__init__()
        self.imagenes = imagenes_estado
        self.estado="Full"
        self.image = imagenes_estado[self.estado]
        self.rect = self.image.get_rect(midbottom=pos)

    def update(self):
        pass