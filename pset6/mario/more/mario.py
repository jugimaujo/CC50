from cs50 import get_int

height = 0
c = 0

while height < 1 or height > 8:
    height = get_int('Height: ')

while height > 0:
    c += 1
    print(' ' * (height - 1), end='')
    print('#' * c, end='')
    print('  ', end='')
    print('#' * c)
    height -= 1