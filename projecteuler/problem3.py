import sys
import math

def isprime(n):
	"""Returns True if n is prime"""
	if n == 2: return True
	if n == 3: return True
	if n % 2 == 0: return False
	if n % 3 == 0: return False

	i = 5
	w = 2
	while i * i <= n:
		if n % i == 0:
			return False
	
		i += w
		w = 6 - w

	return True

factor = 0
num = 600851475143 

for x in range(num/2, 1, -1):
	if num % x == 0 and isprime(x) and x > factor:
		factor = x

print factor
