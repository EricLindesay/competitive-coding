from collections import Counter
import string

def mix(s1, s2):
    c1 = Counter(s1)
    c2 = Counter(s2)
    c1 = dict(filter(lambda elem: elem[1] > 1 and elem[0] in string.ascii_lowercase, c1.items()))
    c2 = dict(filter(lambda elem: elem[1] > 1 and elem[0] in string.ascii_lowercase, c2.items()))

    c1keys = c1.keys()
    c2keys = c2.keys()
    ones = []
    equals = []
    twos = []
    for value in c1.items():
        if value[0] in c2keys:
            if value[1] == c2[value[0]]:
                equals.append("=:"+str(value[0])*value[1])
            elif value[1] > c2[value[0]]:
                ones.append("1:"+str(value[0])*value[1])
            else:
                twos.append("2:"+str(value[0])*c2[value[0]])
        else:
            ones.append("1:"+str(value[0])*value[1])

    for value in c2.items():
        if value[0] not in c1keys:
            twos.append("2:"+str(value[0])*value[1])

    ans = ones+equals+twos

    ans = sorted(ans)
    ans = sorted(ans, key=lambda x: len(x))
    ans.reverse()
    
    return '/'.join(ans)

print(mix("Sadus:cpms>orqn3zecwGvnznSgacs","MynwdKizfd$lvse+gnbaGydxyXzayp"))
