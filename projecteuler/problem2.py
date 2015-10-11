sum = 2

first = 1
second = 2

print first
print second

while(1):
	temp = second 
	second = first + second
	first = temp 

	if second % 2 == 0:
		sum = sum + second

	if second > 4000000:
		print sum
		break

