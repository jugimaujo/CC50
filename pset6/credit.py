from cs50 import get_int, get_string

# Ask for the card's number
card = get_string('Number: ')

lst = list()
rev_sum = 0
final_sum = 0

# Pass into a list the card's individual numbers 
for num in card:
    lst.append(int(num))

# Luhn Algorithm
# Sum each second number of the card multiplied by 2, reversely
for i in range(len(lst) - 2, -1, -2):
    # multiply every digit by 2
    mult = lst[i] * 2
    
    # Separate each algarism if product's result has two algarisms
    if len(str(mult)) > 1:
        for a in str(mult):
            rev_sum += int(a)
    else:
        rev_sum += mult

# Sum the first sum the rest of the card's numbers
for i in range(len(lst) - 1, -1, -2):
    final_sum += lst[i]
final_sum += rev_sum

final_sum = str(final_sum)
if final_sum[len(final_sum) - 1] != '0':
    print('INVALID')
else:
    if len(lst) == 15:
        print('AMEX')
    elif len(lst) == 13 or (len(lst) == 16 and lst[0] == 4):
        print('VISA')
    else:
        print('MASTER CARD')
