def change_cost(word1, word2):
    ret = 0
    for let1, let2 in zip(word1, word2):
        if let1 != let2:
            ret += 1
    return ret


def main(initial_ind, words):
    if len(words) == 1:
        return words[0]

    initial_word = words[initial_ind]
    words.pop(initial_ind)

    min_cost = -1
    next_ind = -1
    for i, word in enumerate(words):
        cost = change_cost(initial_word, word)
        if cost < min_cost or min_cost == -1:
            min_cost = cost
            next_ind = i

    changes = f"{initial_word}\n"+main(next_ind, words[:])
    return changes


t = input()
n = int(t.split(" ")[0])

twords = []
for _ in range(n):
    twords.append(input())

# Probably from kattis

# twords = list(set(twords)) # remove duplicates
# Each word needs to try being the initial word
min_cost = -1
min_string = ""
for i in range(len(twords)):
    gene_order = main(i, twords[:])
    gene_order = gene_order.split("\n")
    string = ""
    prev = ""
    total_cost = 0
    for gene in gene_order:
        if prev:
            ind_gene = twords.index(gene)
            string += f"{twords.index(prev)} {ind_gene}\n"
            total_cost += change_cost(prev, gene)
        prev = gene

    string = string.strip()
    if total_cost < min_cost or min_cost == -1:
        min_cost = total_cost
        min_string = string

print(f"{total_cost}\n{string}")
