cases = int(input())  # num tests

while cases > 0:
    cases -= 1
    
    n,m = [int(x) for x in input().split(" ") if x]  # num inputs for this test
    distances = [int(x) for x in input().split(" ") if x]
        
    energy = m
    total = sum(distances) - m

    if total < 0:
        total = 0
    print(total)