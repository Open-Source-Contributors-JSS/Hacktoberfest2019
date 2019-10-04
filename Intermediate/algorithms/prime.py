“””
following program figures out if the number ‘n’ is a prime number
“””


def isPrime(num):
	for i in range(2, num):
		if num % i == 0:
			return False
	return True

