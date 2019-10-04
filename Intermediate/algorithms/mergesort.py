#Author: dreamcatcher12
#Modeled after geeksforgeeks https://www.geeksforgeeks.org/merge-sort/

def mergeSort(arrInput):
    if len(arrInput) > 1:
        mid = len(arrInput) // 2  # midpoint of input array
        left = arrInput[:mid]  # Dividing the left side of elements
        right = arrInput[mid:]  # Divide into second half
        mergeSort(left)  # Sorting first half
        mergeSort(right)  # Sorting second half
        i = 0
        j = 0
        k = 0
        # Copy data to temp arrInput left[] and right[]
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                arrInput[k] = left[i]
                i += 1
            else:
                arrInput[k] = right[j]
                j += 1
            k += 1

        # Checking if any element was left
        while i < len(left):
            arrInput[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            arrInput[k] = right[j]
            j += 1
            k += 1

