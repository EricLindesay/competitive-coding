def gimme_numbers():
    i = 1
    while True:
        yield(i)
        i += 1


for i in gimme_numbers():
    print(i)
    if i > 22:
        break
    

[[0]*3]
[[0],[0],[0]]

print("12345"[:2])