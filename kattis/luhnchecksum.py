T = int(input())
for t in range(T):
    n = input()

    nl = list(n);

    csum = 0
    for i in range(len(nl)):
        d = nl[len(nl) - 1 - i]
        if i % 2 == 0: 
            csum += int(d) 
            continue

        val = int(d) * 2
        if val > 9:
            digs = list(str(val))
            sum = 0
            for dig in digs:
                sum += int(dig)
            val = sum
        csum += val 
    
    if csum % 10 == 0:
        print("PASS")
    else:
        print("FAIL")
