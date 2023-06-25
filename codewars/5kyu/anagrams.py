from collections import Counter

def anagrams(word, words):
    target = Counter(word)
    return [x for x in words if Counter(x) == target] 

anagrams("laser", ["lazing", "lazy", "lacer", "dada"])
