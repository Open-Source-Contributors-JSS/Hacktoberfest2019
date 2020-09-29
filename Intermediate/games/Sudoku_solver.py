# Author: Om Rawal
# Sudoku solver using Python Pygame and Backtracking



import pygame as pg
import pygame
import numpy as np


pg.init()
pygame.display.set_caption("Sudoku")
screen = pg.display.set_mode((640, 480))
COLOR_INACTIVE = pg.Color('lightskyblue3')
COLOR_ACTIVE = pg.Color('dodgerblue2')
FONT = pg.font.Font(None, 32)
height=40
width=40
a=[ [],
        [],
        [],
        [],
        [],
        [],
        [],
        [],
        []  ]

input_boxes = []

class InputBox:

    def __init__(self, x, y, w, h, text='0'):
        self.rect = pg.Rect(x, y, w, h)
        self.color = COLOR_INACTIVE
        self.text = text
        self.txt_surface = FONT.render(text, True, self.color)
        self.active = False

    def handle_event(self, event):
        if event.type == pg.MOUSEBUTTONDOWN:
            # If the user clicked on the input_box rect.
            if self.rect.collidepoint(event.pos):
                # Toggle the active variable.
                self.active = not self.active
            else:
                self.active = False
            # Change the current color of the input box.
            self.color = COLOR_ACTIVE if self.active else COLOR_INACTIVE
        if event.type == pg.KEYDOWN:
            if self.active:
                if event.key == pg.K_RETURN:
                    get_matrix()
                    

                elif event.key == pg.K_BACKSPACE:
                    self.text = self.text[:-1]
                else:
                    self.text += event.unicode
                # Re-render the text.
                self.txt_surface = FONT.render(self.text, True, self.color)

    def update(self):
        # Resize the box if the text is too long.
        width = max(40, self.txt_surface.get_width()+10)
        self.rect.w = width
        self.txt_surface = FONT.render(self.text, True, self.color)

    def draw(self, screen):
        # Blit the text.
        screen.blit(self.txt_surface, (self.rect.x+5, self.rect.y+5))
        # Blit the rect.
        pg.draw.rect(screen, self.color, self.rect, 2)

  
def possible(x,y,n):
    global a
    for i in range(0,9): #col check for n 
        if a[i][y]==n:
            return False
    for i in range(0,9): #row check for n
        if a[x][i]==n:
            return False
    
    x1=(x//3)*3
    y1=(y//3)*3
    for i in range (0,3):   #check for box
        for j in range(0,3):
            if(a[x1+i][y1+j])==n:
                return False
    return True
def get_results():
    global a 
    global input_boxes
    global screen
    pos=0
    for i in range(0,9):
        for j in range(0,9):
            input_boxes[pos].text=str(a[i][j])
            pos+=1



def solve():
    global a
    for i in range(0,9):
        for j in range(0,9):
            if(a[i][j]==0):
                for n in range(1,10):
                    if(possible(i,j,n)):
                        a[i][j]=n
                        solve()   #recursive solving
                        a[i][j]=0 #backtracking
                return  #none possible <DEADEND> so backtracking
    # print(np.matrix(a))
    get_results() 


def get_matrix():
    global a
    global input_boxes
    pos=0
    for i in range(0,9):
        for j in range(0,9):
            a[i].append(int(input_boxes[pos].text))
            pos+=1
    
    solve()






def main():
    global input_boxes
    for i in range(9):
            for j in range(9):
                input_box1 = InputBox(40+(i*(width+5)),15+(j*(height+5)),height,width)
                input_boxes.append(input_box1)
    # print(len(input_boxes))
    done = False
    myfont = pygame.font.SysFont('Comic Sans MS', 30)
    while not done:
        for event in pg.event.get():
            if event.type == pg.QUIT:
                done = True
            for box in input_boxes:
                box.handle_event(event)
            if event.type==pg.K_RETURN:
                get_matrix(input_boxes)
        for box in input_boxes:
            box.update()

        screen.fill((30, 30, 30))
        for box in input_boxes:
            box.draw(screen)
        textsurface = myfont.render('Enter The numbers in grid and press enter to view results:', False, (255, 0, 0))
        screen.blit(textsurface,(40,410))
        pg.display.flip()


if __name__ == '__main__':
    main()
    pg.quit()
