'''
Ternary search is a divide and conquer algorithm that can be used to find an element in an array. It is similar to binary search where we divide the array into two parts but in this algorithm. In this, we divide the given array into three parts and determine which has the key (searched element). We can divide the array into three parts by taking mid1 and mid2 which can be calculated as shown below. Initially, l and r will be equal to 0 and n-1 respectively, where n is the length of the array.
'''


def ternary_search (L, key):
   left = 0
   right = len(L) - 1
   while left <= right:
      ind1 = left
      ind2 = left + (right - left) // 3
      ind3 = left + 2 * (right - left) // 3
      if key == L[left]:
         print("Key found at:" + str(left))
         return
      elif key == L[right]:
         print("Key found at:", str(right))
         return
      elif key < L[left] or key > L[right]:
         print("Unable to find key")
         return
      elif key <= L[ind2]:
         right = ind2
      elif key > L[ind2] and key <= L[ind3]:
         left = ind2 + 1
         right = ind3
      else:
         left = ind3 + 1
   return

ternary_search([6,12,18,22,29,37,38,41,51,53,55,67,73,75,77,81,86,88,94],86)

