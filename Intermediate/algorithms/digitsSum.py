'''
    Function to sum numbers digits recursively
'''

def sumDigits(n):
    if n <= 9:
        return n
    else:
        return n % 10 + sumDigits(n//10)

print(sumDigits(123))