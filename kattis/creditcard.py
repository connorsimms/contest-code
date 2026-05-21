n = int(input())

for i in range(n):
    line = input().split()

    R = list(line[0].split('.'))
    B = list(line[1].split('.'))
    M = list(line[2].split('.'))

    R_c = int(R[0]) * 100

    if R[1][0] == "0":
        R_c += int(R[1][1])
    else:
        R_c += int(R[1][0]) * 10
        R_c += int(R[1][1])

    M_c = int(M[0]) * 100 + int(M[1])
    B_c = int(B[0]) * 100 + int(B[1])
    
    ans = 0
    while B_c > 0 and ans <= 1201:
        ans = ans + 1;

        if (ans > 1):
            B_c -= M_c

        if (B_c <= 0):
            break

        interest = B_c * R_c / 10000

        r_interest = round(interest);

        B_c += r_interest;
    ans = ans - 1

    if ans <= 1200:
        print(ans)
    else:
        print("impossible")

