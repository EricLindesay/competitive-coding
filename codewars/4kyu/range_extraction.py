def solution(args):
    sol = []
    i = 0
    while i < len(args):
        q = num_ascending(args, i)
        q += 1 #account for the current number as well.
        if q > 2:
            sol.append(str(args[i])+"-"+str(args[i+q-1]))
            i += q
        else:
            sol.append(str(args[i]))
            i += 1    
    return ','.join(sol)


def num_ascending(args, ind):
    i = ind
    before = args[i]
    while i < len(args)-1:
        if before == args[i+1]-1:
            i += 1
            before = args[i]
        else:
            break
    return i-ind

print(solution([-6,-3,-2,-1,0,1,3,4,5,7,8,9,10,11,14,15,17,18,19,20]))
