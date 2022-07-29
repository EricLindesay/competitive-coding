import random


def get_ans(n, k):
    count = 1
    valid = 0
    while True:
        if count%n:
            valid += 1
            if valid == k:
                return count

        count += 1


print("INPUT")
print("20")
ans = []
for i in range(20):
    n = random.randint(2, 200)
    k = random.randint(1, 200)
    print(f"{n} {k}")

    ans.append(get_ans(n, k))


print("OUTPUT")
print(ans)