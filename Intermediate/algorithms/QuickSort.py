#!/usr/bin/env python
# coding: utf-8

def partition(arr,low,high): 
    i = ( low-1 )        
    pivot = arr[high]     
  
    for j in range(low , high): 
  
        # If current element is smaller than or equal to pivot 
        if   arr[j] <= pivot: 
          
            # increment index of smaller element 
            i = i+1 
            arr[i],arr[j] = arr[j],arr[i] 
  
    arr[i+1],arr[high] = arr[high],arr[i+1] 
    return ( i+1 ) 
  


# arr[] --> Array to be sorted, 
# low  --> Starting index, 
# high  --> Ending index 
  
def quickSort(arr,low,high): 
    if low < high: 
  
        # pi is partitioning index, arr[p] is now at right place 
        pi = partition(arr,low,high) 
  
        # Separately sort elements before partition and after partition 
        quickSort(arr, low, pi-1) 
        quickSort(arr, pi+1, high) 
  

#Input format: 54 2 36 86 3
arr= [int(a) for a in input().split()]
n = len(arr) 
quickSort(arr,0,n-1) 
print ("Sorted array is:") 
for i in range(n): 
    print ("%d" %arr[i]) 

