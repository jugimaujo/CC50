from cs50 import get_string

text = get_string('Text: ').strip()
letter, word, sentence = 0, 1, 0 

for c in text:
    if c.isalpha():
        letter += 1
    elif c == ' ':
        word += 1
    elif c in ['.', '!', '?']:
        sentence += 1
        
L = (letter / float(word)) * 100
S = (sentence / float(word)) * 100

X =  0.0588 * L - 0.296 * S - 15.8

if X < 1:
    print('Before Grade 1')
elif X >= 16:
    print('Grade 16+')
else:
    print(f'Grade {X:.0f}')
