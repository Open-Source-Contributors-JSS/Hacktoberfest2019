print("hi this is a calculator")
print("select a task to do")
print("1. find area of a room/rectrangle")
print("2. find area of a circle ")
choice1 = int(input("1/2: "))
if choice1 == 1:
    width = float(input("enter width= "))
    height = float(input("enter height= "))

    Area = width * height

    Perimeter = 2 * (width + height)

    print("\n Area of rectangle/room= %.2f " % Area)
    print(" perimeter of rectangle/room= %.2f" % Perimeter)
elif choice1 == 2:

    print("choose an option to find area and circumference ofa circle ")
    print("1. diameter")
    print("2. radius")
    choice = input("enter a choice=  ")
    if choice == "1":
        d = float(input("enter diameter= "))
        r = d / 2
        pie = 22 / 7
        Area = pie * r * r
        circumference = 2 * pie * r
        print("radius= %.2f" % r)
        if d == 22:
            print("its gonna be difficult")
            print("\n Area of circle=  %.2f" % Area)
            print(" circumference of circle= %.2f" % circumference)

        else:
            print("\n Area of circle=  %.2f" % Area)
            print(" circumference of circle= %.2f" % circumference)

    elif choice == "2":
        r = int(float(input("enter radius= ")))
        pie = 22 / 7
        Area = pie * r * r
        circumference = 2 * pie * r
        print("\n Area of circle=  %.2f" % Area)
        print(" circumference of circle= %.2f" % circumference)

    else:
        print("invalid option")
