kb = ["`1234567890-=",
      "QWERTYUIOP[]\\",
      "ASDFGHJKL;'",
      "ZXCVBNM,./"]

map = {" ": " "}

for row in kb:
    lr = list(row)
    for i in range(1, len(lr)):
        map[lr[i]] = lr[i-1]

while True:
    try:
        line = input()
    except EOFError:
        break

    if len(line) == 0: break
    
    ll = list(line)
    for i in range(len(ll)):
        print(map[ll[i]], end="")
    print()


