'''
Recursive Factorial
This is a factorial algorithm using an easy recursive solution.
'''

def factorial(n):
    if n <= 1:
        return 1
    else:
        return n * factorial(n - 1)

print(factorial(8))
print(8 * factorial(7))