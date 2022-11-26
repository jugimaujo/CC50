def main():    
    from sys import argv
    
    # Check if there are enough arguments for the program
    if len(argv) != 3:
        print('Usage: python dna.py data.csv sequence.txt')
    
    dna = argv[2]
    
    suspect = ' '
    names = []
    strs = []
    people = {}
    
    with open(argv[1], 'r') as csv_file:
        for i, row in enumerate(csv_file):
            if i == 0:
                strs = [s for s in row.strip().split(',')[1:]]
            else:
                curr_person = row.strip().split(',')[0]
                names.append(curr_person)
                people[curr_person] = [int(Str) for Str in row.strip().split(',')[1:]]
                
    for k, v in people.items():
        curr_max = []
        for s in strs:
            curr_max.append(STR_counter(dna, s))
            if curr_max == v:
                suspect = k
    
    if suspect.isalpha():
        print(suspect)
    else:
        print('No match')

    
def STR_counter(DNA, STR):
    i, cont, max_str = 0, 0, 0
    
    with open(DNA, 'r') as seq:
        seq = seq.read()
        while i + len(STR) < len(seq):
            j = i + len(STR)
            sub_str = seq[i:j]
            if sub_str != STR:
                i += 1
                if max_str < cont:
                    max_str = cont
                cont = 0
            else:
                cont += 1
                i += len(STR)
                
    return max_str
    
main()