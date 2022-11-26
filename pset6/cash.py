from cs50 import get_float

# Variable of the change
change = -1

# Ask for positive if change is negative
while change < 0:
    change = get_float('Change owed: ')

# Change's owed rest multiplied by 100 for precision
rest = change * 100
# Number of coins given
coins = 0

while rest >= 25:
    rest -= 25
    coins += 1
while rest >= 10:
    rest -= 10
    coins += 1
while rest >= 5:
    rest -= 5
    coins += 1
while rest >= 1:
    rest -= 1
    coins += 1

print(coins)