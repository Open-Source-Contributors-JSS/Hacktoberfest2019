'''
    Resursive Greatest Common Divisor function between two numbers
'''
def gcd(a, b):
    if a % b == 0:
        return b
    else:
        return gcd(b, a % b)

print(gcd(50, 20))