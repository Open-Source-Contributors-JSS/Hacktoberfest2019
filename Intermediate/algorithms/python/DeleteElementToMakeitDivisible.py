

def divisible(num, d): 
    
    arr= list(num)

    for i in range(len(arr)):
        arr[i]= int(arr[i])
    
    counter=1
    for i in range(len(arr)-1):

        for j in range(0, len(arr)-1):
            temp=arr[0:j]+arr[j+counter:]
            num=number(temp)
          
            if num/d==num//d:
                return counter
        counter+=1
        
    else:
        return -1

  
  
# Driver Code 
if __name__=='__main__': 
    num = input()
    d= int(input())
    print(divisible(num, d))
  