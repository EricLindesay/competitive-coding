
n = input().split(" ")

with open("f.txt", "w") as f:
    for i,s in enumerate(n):
        q = s.split(":")
        f.write(f"node{i} = Node(\"{q[0]}\", {q[1]})\n")

    f.write("all_nodes = [")
    for i,s in enumerate(n):
        f.write(f"node{i},")
