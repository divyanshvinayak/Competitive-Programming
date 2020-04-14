def modulo(p, q):
    return (pow(q, MOD - 2, MOD) * (p % MOD)) % MOD

MOD = 998244353
for _ in range(int(input())):
    s = input()
    if s == '#':
        s = '(#^#)'
    output = []
    operator = []
    for i in range(len(s)):
        if s[i] != ')':
            if s[i] == '#':
                output.append([1, 1, 1, 1])
            elif s[i] != '(':
                operator.append(s[i])
        else:
            op = operator.pop()
            x = output.pop()
            y = output.pop()
            temp = [0, 0, 0, 0]
            if op == '&':
                for j in range(4):
                    for k in range(4):
                        temp[j & k] += x[j] * y[k]
            elif op == '^':
                for j in range(4):
                    for k in range(4):
                        temp[j ^ k] += x[j] * y[k]
            else:
                for j in range(4):
                    for k in range(4):
                        temp[j | k] += x[j] * y[k]
            output.append(temp)
    s = sum(output[0])
    print(modulo(output[0][0], s), modulo(output[0][3], s), modulo(output[0][1], s), modulo(output[0][2], s))