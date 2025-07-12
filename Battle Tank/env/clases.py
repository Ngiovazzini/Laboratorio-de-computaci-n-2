import pygame
import pygame as py



class Brick(py.sprite.Sprite):
    def __init__(self, x,y,ruta,tile_size):
        super().__init__()
        image_s_escalar = pygame.image.load(ruta).convert()
        self.image = py.transform.scale(image_s_escalar,(tile_size,tile_size) )
        self.rect = self.image.get_rect(topleft=(x,y))


    def update(self):
        pass

class Tank(py.sprite.Sprite):
    def __init__(self, x, y,imagenes):
        super().__init__()

        self.img_der = imagenes[0]
        self.img_izq = imagenes[1]
        self.img_abajo = imagenes[2]
        self.img_arriba = imagenes[3]
        self.image = self.img_der
        self.image =imagenes[0]
        self.rect = self.image.get_rect()#requerido para que Group() sepa como dibujarlos
        self.rect.topleft = (x, y)
        self.velocidad=2
    def update(self,obstaculos):
        dy = 0
        dx = 0
        teclas=py.key.get_pressed() #esto devuelve un true si una tecla es presionada
        if teclas[py.K_UP]:
            dy+=self.velocidad
            self.image = self.img_arriba

        if teclas[py.K_DOWN]:
            dy-=self.velocidad
            self.image = self.img_abajo

        if teclas[py.K_LEFT]:
            dx+=self.velocidad
            self.image = self.img_izq

        if teclas[py.K_RIGHT]:
            dx-=self.velocidad
            self.image =self.img_der

        self.rect.x -= dx
        self.rect.y -= dy

        if pygame.sprite.spritecollide(self, obstaculos, False):
            self.rect.y+=dy
            self.rect.x+=dx


        if self.rect.left < 0:
            self.rect.left=800
        if self.rect.left > 800:
            self.rect.left = 0
        if self.rect.top < 0:
            self.rect.top=600
        if self.rect.top > 600:
            self.rect.top = 0



class TankEnemy(Tank):
    def __init__(self, x, y,imagenes):
        super().__init__( x, y,imagenes)

    def update(self,obstaculos,player_tank_group):
        self.rect.y -= 1
        if pygame.sprite.spritecollide(self, obstaculos, False) or pygame.sprite.spritecollide(self, player_tank_group, False):
            self.rect.x -= 1
            self.rect.y += 1
        if pygame.sprite.spritecollide(self, obstaculos, False):
            self.rect.x += 1
            self.rect.y -= 1





        if self.rect.left < 0:
            self.rect.left=800
        if self.rect.left > 800:
            self.rect.left = 0
        if self.rect.top < 0:
            self.rect.top=600
        if self.rect.top > 600:
            self.rect.top = 0
        #if pygame.sprite.spritecollide(self, obstaculos, False):
            #self.rect.y -= self.velocidad
            #self.rect.x -= self.velocidad

