"""-----------------
HACKTOBERFEST
User: retro-node
Date Edited: 5th Oct 2019
Sorts array in place using insertion sort
-----------------"""

import time
import numpy as np

def swapTwoAr(arr, pos1, pos2): #not utilising built ins
    temp = arr[pos1]
    arr[pos1] = arr[pos2]
    arr[pos2] = temp
    return arr

def insertionSort(A):
    start = time.time()
    try:
        for ii in range(1, len(A)):
            i = ii
            while(i > 0) and (A[i-1] > A[i]):
                swapTwoAr(A, i, i-1)
                i = i - 1
    except TypeError:
        print("Error in input")
    end = time.time()
    timeT = end - start
    duration = round(timeT, 5)
    print("---Finished in ", duration, "seconds---")


testArr = np.random.randint(0, 999, size=(100))
insertionSort(testArr)
print(testArr)
