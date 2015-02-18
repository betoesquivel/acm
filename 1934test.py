import math

def calc(s, d):
    c = d + ( s*s - s) / 2.0
    return math.ceil(( math.sqrt(8*c + 1) - 1)/2.0)


if (__name__ == '__main__'):
    while (True):
        try:
            case = raw_input()
            arr = case.split()
            s = int(arr[0])
            d = int(arr[1])

            print int(calc(s,d))
        except EOFError:
            break
