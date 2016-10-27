# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair
# and each of a and b are called amicable numbers.

# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110;
# therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

# Evaluate the sum of all the amicable numbers under 10000.

def calc_divisors(num):
    divisorSum = 0
    for a in range(1, int(num/2) + 1):
        if num % a == 0:
            divisorSum += a  # add up all the divisors of num
    return divisorSum

totalSum = 0
myList = []
for num in range(1, 10001):
    numDivisors = calc_divisors(num)
    if calc_divisors(numDivisors) == num and numDivisors != num and num not in myList:
        myList.append(num)
        if numDivisors not in myList:
            myList.append(numDivisors)
for a in myList:
    totalSum += a
print(totalSum)
