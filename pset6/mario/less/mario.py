from cs50 import get_int

height = 0
c = 1

while 1 > height or height > 8:
    height = get_int('Height: ')

while height > 0:
    print(' ' * (height - 1), end = '')
    print('#' * c)
    height -= 1
    c += 1