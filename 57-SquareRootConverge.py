# It is possible to show that the square root of two can be expressed as an infinite continued fraction.
# sqrt(2) = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
# By expanding this for the first four iterations, we get:
# 1 + 1/2 = 3/2 = 1.5
# 1 + 1/(2 + 1/2) = 7/5 = 1.4
# 1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
# 1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...
# 1393/985, is the first example where the number of digits in the numerator > number of digits in the denominator.
# In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?

# I solved this by noticing a pattern that we are just adding 1 to our last answer
# then putting it under one (flipping the fraction)
# then add one again


import time


def num_digs(num):
    knt = 0
    while num:
        knt += 1
        num /= 10
    return knt

t0 = time.time()
numerator = 3
denominator = 2
knt = 0
for iterations in range(1, 1000):
    temp = denominator  # Keep current denominator value
    denominator += numerator  # we are adding one to our previous value so we can do this
    numerator = temp
    numerator += denominator  # set numerator to our original denominator plus our new denominator
    if num_digs(numerator) > num_digs(denominator):
        knt += 1
print knt
t1 = time.time()
print t1-t0
