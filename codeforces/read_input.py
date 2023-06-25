

n = int(input())

while n > 0:
    n -= 1
    
    m = int(input()) - 1
    ans = []
    while m > 0:
        ans.append([int(x) for x in input().split(" ") if x])
        m -= 1

    print(f"{ans=}")