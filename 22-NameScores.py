# Using names.txt, a 46K text file containing over five-thousand first names, sort it into alphabetical order.
# Then working out the alphabetical value for each name,
#  multiply this value by its alphabetical position in the list to obtain a name score.

# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53,
# is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

# What is the total of all the name scores in the file?

file = open("names.txt", "r")  # Open names.txt for reading
alphabet = ['','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
listNames = []
names = file.read()
knt = 0
for name in names.split(","):  # Read in one name at a time (stopping when we hit a ,)
    name = name.split("\"")    # Get rid of the "
    listNames.append(name)
    knt += 1
listNames.sort()               # Sort names in alphabetical order
total = 0
nameKnt = 1
for singleName in listNames:
    nameTotal = 0
    for letter in singleName[1]:
        nameTotal += alphabet.index(letter.lower())  # Add the position of our letter in alphabet to name total
    total += nameTotal * nameKnt
    nameKnt += 1
print(total)
