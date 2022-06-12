
def find_ind(top_x, val):
    for i in range(len(top_x)-1, -1, -1):  # loop backwards
        if val < top_x[i]:  # insert below
            return i+2
    return 1  # insert at front


n,q = [int(x) for x in input().split(" ") if x]
p = [int(x) for x in input().split(" ") if x]

ans = [] # [(x,y)]
while q > 0:
    x,y = [int(x) for x in input().split(" ") if x]
    top_x = []
    bottom_y = []

    for i in p:
        if not top_x:
            top_x.append(i)
            #bottom_y.append(i)
            continue

        if i > top_x[-1] or len(top_x) < x:
            pos = find_ind(top_x, i)
            if pos:
                if (pos-1) >= len(top_x):
                    top_x.append(i)
                else:
                    top_x.insert(pos-1, i)

                if len(top_x) > x:
                    top_x.pop()

    print(sum(top_x[y-1:]))
    q -= 1