import itertools

i = 0
existingDwarves = []
while(i < 9):
    existingDwarves.append(int (raw_input()))
    i += 1

combinations = list(itertools.combinations(existingDwarves, 7))

solution = ()
for i in combinations:
    if ( sum(i) == 100 ):
        solution = i
        break

sortAns = sorted(list(solution))
for x in sorted( solution ):
    print x
