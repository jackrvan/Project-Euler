# There are exactly ten ways of selecting three from five, 12345:

# 123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

# It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

# How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?

import math

def choose(n, r):
    return math.factorial(n)/(math.factorial(r)*(math.factorial(n-r)))

total = 0
for n in range(1, 101):
    find = False
    for r in range(2, n+1):
        if choose(n, r) > 1000000:
            total += 1
print(total)