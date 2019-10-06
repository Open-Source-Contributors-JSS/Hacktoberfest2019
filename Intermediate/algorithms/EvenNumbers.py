#Program to find all the pair numbers between two numbers 
exit = False

Ll = int (input("Enter the lower limit of the interval:")) #Lower limit

ul = 0 #upper limit

while True:
    ul = int (input ("enter the upper limit of the interval:"))
    
    if(Ll < ul):
        break
aux = Ll

if Ll % 2 == 0:

    print(aux)

else:

    if aux+1>=ul:
        exit = True
    else:
        aux = aux + 1
        print(aux)

if exit == False:
    if aux+2<ul:

        while True:

            aux = aux+2
            print(aux)
        
            if(aux+2>=ul):
                break
        
input ("Press enter to exit")