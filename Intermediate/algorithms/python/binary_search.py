def binarySearch(Number, SortedList):
      Low = 0
      High = len(SortedList) - 1
      while Low <= High :
            Mid = (High + Low) // 2
            if SortedList[Mid] == Number:
                  return Mid
            elif SortedList[Mid] > Number :
                  High=Mid - 1
            else :
                   Low = Mid + 1

def main():
      my_list = [1,2,30,46,58,69,74,83,90]
      my_list = sorted(my_list)
      print ("This is my array:", my_list)
      number=input("What number are you looking for? ")
      number = int(number)
      Sort = binarySearch(number, my_list)
      print ("The position in the array is:",Sort)

if __name__ == "__main__":
      main()