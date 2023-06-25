import re

n = int(input())

ans = 0
rose = r"[r|R][o|O][s|S][e|E]"
pink = r"[p|P][i|I][n|N][k|K]"
for _ in range(n):   
    word = input()
    if re.search(rose, word) or re.search(pink, word):
        ans += 1

if ans == 0:
    print("I must watch Star Wars with my daughter")
else:
    print(ans)