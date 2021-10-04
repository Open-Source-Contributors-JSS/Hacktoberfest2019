if __name__ == '__main__':
    list1 = []
    n = int(input())
    for i in range(n):
        s, *d = input().split()
        d = list(map(int, d))
        if s == "print":
            print(list1)
        else:
            getattr(list1, s)(*d)