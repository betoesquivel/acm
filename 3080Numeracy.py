

T = int( raw_input() )

while (T > 0):
    exp = ""
    i = 0
    while (i < 3):
        exp += raw_input()
        i += 1

    eq = raw_input()
    ans = raw_input()
    if (eq == '='):
        try:
            x = eval(exp)
            try:
                a = int(ans)
                if (x == a):
                    print 'Yes'
                else:
                    print 'No'
            except ValueError:
               print 'No'
        except SyntaxError:
            print 'No'
    else:
        print 'No'

    T -= 1
