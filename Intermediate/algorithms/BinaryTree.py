import pygame as pg
import random

WIDTH=400
HEIGHT=400
GAME_NAME="Test"
FPS=60
BG_COLOR=(0,0,0)

class Game():
    def __init__(self):
        self.running=True
        self.__initPygame()
        self.__initBlocks()

    def __initBlocks(self):

        rect1= pg.Rect(0,0,20,20)
        rect1.bottomleft=(100,HEIGHT)

        rect2= pg.Rect(0,0,50,50)
        rect2.bottomleft=(200,HEIGHT)

        self.small=Block(rect1,1)
        self.big=Block(rect2,100)

    def __initPygame(self):
        pg.init()
        self.clock=pg.time.Clock()
        self.win=pg.display.set_mode((WIDTH,HEIGHT))
        self.win.fill(BG_COLOR)
        pg.display.set_caption(GAME_NAME)

    def run(self):
        while self.running:
            self.events()
            self.update()
            self.draw()
            self.clock.tick(FPS)
        pg.quit()

    def events(self):
        for event in pg.event.get():
            if event.type == pg.QUIT:
                self.running=False

    def update(self):
        pass

    def draw(self):
        self.small.draw(self.win)
        self.big.draw(self.win)
        pg.display.update()

class Block():
    def __init__(self,rect,mass):
        self.rect=rect
        self.mass=mass

    def draw(self,surface):
        pg.draw.rect(surface,(255,100,0),self.rect)




g=Game()
g.run()
