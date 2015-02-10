# Generate all subsets of the list v of length l.
def subsets(v, l):
    return _subsets(v, 0, l, [])

def _subsets(v, k, l, acc):
    if l == 0:
        return [acc]
    else:
        r = []
        for i in range(k, len(v)):
            r.extend(_subsets(v, i + 1, l - 1, acc + [v[i]]))
        return r


def findVirus(program, virus):
    vSet = list(virus)
    i = len(virus)
    while i > 0:
        vSubSets = subsets(vSet, i)

        for subset in vSubSets:
            s = ''.join(subset)
            if s in program:
                return len(subset)
        i -= 1
    return 0

program = raw_input()
virus = raw_input()
print findVirus(program, virus)
