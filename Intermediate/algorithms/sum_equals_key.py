#return True if sum of any two num in list equals key O(n)

num=[]
n=int(input())
for x in range(n):
    num.append(int(input()))
key=int(input())
for x in range(n):
    if key-num[x] in num:
        print(True)
        exit() #quit()
print(None)
