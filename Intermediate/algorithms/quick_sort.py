#!/usr/bin/env python3

"""
Quicksort
This is a commonly used sorting algorithm and as the name implies it is quick.
The worst case for time complexity is O(n^2) but this is prevented by shuffling the array first.
The best case performance is O(n log n) which is also the average performance.
The way it works is it first shuffles the list. It then partitions the list by taking an element as the pivot
and then moves all elements smaller than the element to the left and all elements bigger to the right.
It then takes the two sub lists either side of the pivot and repeats the partition process.
@author Justin Giffard
"""
import random

def quickSort(array):
    random.shuffle(array)
    sort(array, 0, len(array)-1)

""" does the quicksort"""
def sort(array, low, high):
    if low < high:
        pivot = partition(array, low, high)
        sort(array, low, pivot -1)
        sort(array, pivot+1, high)

"""
This function function takes the last element as the pivot and places all smaller elements to the left and
all greater to the right and returns the index of the pivot
"""
def partition(array, low, high):
    pivot = array[high]
    i = low - 1
    for j in range(low, high):
        if array[j] < pivot:
            i+=1
            array[i], array[j] = array[j], array[i]
    array[i+1], array[high] = array[high], array[i+1]
    return i+1

print("Enter numbers seperated by a space then press enter:")
arr = list(map(int,input().split()))
n = len(arr)
quickSort(arr)
print("After sort: ")
for i in range(0, n) :
    print(arr[i], end=' ')
print() #adds new line at the end of the loop so that the prompt is on new line
