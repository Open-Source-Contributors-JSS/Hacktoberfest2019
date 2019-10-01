import math
import turtle
def draw_pie(t,n,r):
    polypie(t,n,r)
    t.pu()
    t.fd(r*2+10)
    t.pd()
def polypie(t,n,r):
    angle=360/n
    for i in range(n):
        isosceles(t,r,angle/2)
        t.lt(angle)
def isosceles(t,r,angle):
    y=r*math.sin(angle*math.pi/180)
    t.rt(angle)
    t.fd(r)
    t.lt(90+angle)
    t.fd(2*y)
    t.lt(90+angle)
    t.fd(r)
    t.lt(180-angle)
bob=turtle.Turtle()
bob.pu()
bob.bk(130)
bob.pd()

size=40
draw_pie(bob,5,size)
draw_pie(bob,6,size)
draw_pie(bob,7,size)
draw_pie(bob,8,size)
draw_pie(bob,10,60)
bob.hideturtle()
turtle.mainloop()
