#  the sequence Fn of Fibonacci numbers is defined by the recurrence relation  Fn = Fn-1 + Fn-2 with seed values  F0 = 0 and F1 = 1

# Function for nth Fibonacci number Use recursion 

def Fibonacci(n): 
	if n<0: 
		print("Incorrect input") 
	# First Fibonacci number is 0 
	elif n==1: 
		return 0
	# Second Fibonacci number is 1 
	elif n==2: 
		return 1
	else: 
		return Fibonacci(n-1)+Fibonacci(n-2) 

# Driver Program 

print(Fibonacci(9))