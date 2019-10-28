# Input: a single integer n denoting a list of [1..n]
# Output: a single list contains all the prime numbers from 1 to n

def sieveOfEratosthenes(n):
    l = list(range(2, n+1))
    lastNumber = 1
    while len(l) > 0 and lastNumber <=n:
        lastNumber += 1
        for i in l:
            if i != lastNumber and i % lastNumber == 0:
                l.remove(i)
    return l

n = 100
res = sieveOfEratosthenes(n)
print(res)