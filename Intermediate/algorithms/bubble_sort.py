#!/usr/bin/env python3

"""
Bubble Sort
@author Justin Giffard

This is a simple to understand sorting algorithm but not efficient for large lists,
it has a time complexity of O(n^2) at worst and O(n) at best (averages O(n^2)).
The way it works is it looks at the first element and compares it to each of the other
elements and swops if the value is lower. Once it reaches the end of the list the smallest value
is in the first position and then it moves to the second element and repeats. There is a small optimisation
in this implementation that counts the number of changes in the iteration of the nested loop and if there
are no swops then stops the outerloop as the list is sorted
"""

def bubbleSort(array):
    n = len(array)
    for i in range(n):
        swops = 0
        for j in range(i+1, n):
            if array[j] < array[i]:
               array[j], array[i] = array[i], array[j]
               swops += 1
        if swops == 0:
            break

print("Enter numbers seperated by a space then press enter:")
arr = list(map(int,input().split()))
n = len(arr)
bubbleSort(arr)
print("After sort: ")
for i in range(0, n) :
    print(arr[i], end=' ')
print()
