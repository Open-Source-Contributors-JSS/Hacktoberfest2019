# Function for printing first `n` number of fibonacci numbers 

def Fibonacci(n):
  x = 0
  y = 1
  if n<0:
    print("Incorrect input")
  else: 
    for i in range(0, n):
      print(y, end = ' ')
      a = x + y
      x = y
      y = a

# Calling the Function
Fibonacci(21)
