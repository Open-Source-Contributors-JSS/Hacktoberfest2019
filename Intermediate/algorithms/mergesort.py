def mergeSort(nList, left, right):
    if(right-left>1):
        middle = (left+right)//2
        mergeSort(nList, left, middle)
        mergeSort(nList, middle, right)
        mergeCombine(nList, left, middle, right)

def mergeCombine(nList, left, middle, right):
    lList = nList[left:middle]
    rList = nList[middle:right]
    k, i, j = left, 0, 0
    while(left+i<middle and middle+j<right):
        if(lList[i]<=rList[j]):
            nList[k] = lList[i]
            i+=1
        else:
            nList[k] = rList[j]
            j+=1
        k+=1
    if(left+i<middle):
        while(k<right):
            nList[k] = lList[i]
            i,k = i+1,k+1
    else:
        while(k<right):
            nList[k] = rList[j]
            j,k = j+1,k+1

nList = [int(x) for x in input('Enter the array of elements to be sorted: ').split()]
mergeSort(nList,0,len(nList))
print('The sorted array: '+str(nList))