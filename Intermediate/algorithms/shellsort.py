def shellSort(nList):
    gap = len(nList)//2
    while(gap>0):
        for i in range(gap,len(nList)):
            key = nList[i]
            j = i
            while( j >= gap and nList[j - gap]> key):
                nList[j] = nList[j - gap]
                j-=gap
            nList[j] = key
        gap //=2 

nList = [int(x) for x in input('Enter the array of elements to be sorted: ').split()]
shellSort(nList)
print('The sorted array: '+str(nList))