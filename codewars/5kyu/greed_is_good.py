# https://www.codewars.com/kata/5270d0d18625160ada0000e4/train/python
from collections import Counter

def score(dice):
	score3 = {1: 1000, 2: 200, 3: 300, 4: 400, 5: 500, 6: 600}
	score1 = {1: 100, 2: 0, 3: 0, 4: 0, 5: 50, 6: 0}
	c = Counter(dice)

	score = 0
	for value in c.items():
		score += (value[1] // 3) * score3[value[0]]
		score += (value[1] % 3) * score1[value[0]]
	
	#score = sum([((value[1] // 3)*score3[value[0]]) + ((value[1] % 3)*score1[value[0]]) for value in c.items()])

	return score

print(score([1,1,1,1,3]))
