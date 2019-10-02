def triangle(n):
    for i in range(1, n+1):
        for x in range(i):
            print("* ", end='')
        print("\n")

n = int(input("Insert n value : "))
print()
triangle(n)
