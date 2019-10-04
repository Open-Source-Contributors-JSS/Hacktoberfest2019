def linear_search(array,key):
    for i in range(len(array)):
        if array[i]==key:
            return i
    return -1
n=int(input('Enter Size of Array: '))

arr=[input('Enter Element %d : '%(i+1)) for i in range(n)]
key=input('Enter Key : ')

ans=linear_search(arr,key)
if ans==-1:
    print ('ELEMENT NOT FOUND')
else:
    print ('ELEMENT FOUND AT POSITION %d'%(ans+1))
