K = int(input())

for k in range(K):
    line = input()
    inp = line.split()
    dset = inp[1]

    digits = list("0123456789ACDEFHJKLMNPRTVWX")
    dtoi = {};
    for i in range(len(digits)):
        dtoi[digits[i]] = i

    num = dset[0:8]
    check = dset[8]

    c = 2 * dtoi[num[0]] + \
        4 * dtoi[num[1]] + \
        5 * dtoi[num[2]] + \
        7 * dtoi[num[3]] + \
        8 * dtoi[num[4]] + \
        10 * dtoi[num[5]] + \
        11 * dtoi[num[6]] + \
        13 * dtoi[num[7]]  
    c = c % 27

    if c != dtoi[check]:
        print(inp[0], "Invalid")
        continue

    val = 0
    for i in range (len(num)):
        val += 27 ** (len(num) - 1 - i) * dtoi[num[i]]

    print(inp[0], val)

    

