def selection_sort(array):
    for i in range(len(array)):
        tmp=min(array[i:len(array)])
        array.remove(min(array[i:len(array)]))
        array.insert(i,tmp)
    return array

n=int(input('Enter Size of Array: '))
arr=[int(input('Enter Element %d : '%(i+1))) for i in range(n)]

print ('Original Array : ',arr)
print ('Sorted Array : ',selection_sort(arr))
