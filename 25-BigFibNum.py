# The Fibonacci sequence is defined by the recurrence relation:

# Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.

# The 12th term, F12, is the first term to contain three digits.

# What is the index of the first term in the Fibonacci sequence to contain 1000 digits?

def countDigs(num):
    numDigits = len(str(num))
    return numDigits

num1 = 1
num2 = 1
index = 2
while 1:  # Bad practice but fine for now
    nextNum = num1 + num2
    num1 = num2
    num2 = nextNum
    # Up to here simply gets next fibonacci number
    index += 1
    numDigs = countDigs(nextNum)
    if numDigs > 999:
        break
print("index = " + str(index))
