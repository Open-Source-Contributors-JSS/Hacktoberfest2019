def funcInput2():
    return list(map(str,input().split()))
longest = ''
listOfStrings = funcInput2()
firstString = listOfStrings[0]
restOfList = listOfStrings[1:]
for i in range(0,len(firstString)):
    flag = 0
    for j in range(i+1,len(firstString)):
        for k in restOfList:
            if(firstString[i:j] not in k):
                flag = 1
                break
        if(flag==1):
            break
        else:
            longest = firstString[i:j]
print(longest)