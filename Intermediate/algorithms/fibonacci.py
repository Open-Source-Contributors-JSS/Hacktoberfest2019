'''
Fibonacci Solutions

These are some fibonacci's algorithm different implementations using:
- Recursive solution
- Dictionary
- A library function
'''

def fibonacci1(n):
    #print(n)
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci1(n - 1) + fibonacci1(n - 2)

f = {}
def fibonacci2(n):
    #print(n)
    if n == 1 or n == 2:
        return 1
    else:
        if n not in f:
            f[n] = fibonacci2(n - 1) + fibonacci2(n - 2)
        return f[n]

from functools import lru_cache #lru = least recently used
@lru_cache(maxsize=None)
def fibonacci3(n):
    #print(n)
    if n == 1 or n == 2:
        return 1
    else:
        return fibonacci3(n - 1) + fibonacci3(n - 2)

print(fibonacci1(8))
print(fibonacci2(8))
print(fibonacci3(8))