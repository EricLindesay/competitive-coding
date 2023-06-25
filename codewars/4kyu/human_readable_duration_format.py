# https://www.codewars.com/kata/52742f58faf5485cae000b9a/train/python
import datetime

def format_duration(seconds):
	if seconds == 0:
		return "now"

	words = ["second", "minute", "hour", "day", "year"]

	time_delta = str(datetime.timedelta(seconds=seconds))
	td = time_delta.split()
	tdsplit = td[len(td)-1].split(':')

	amounts = []
	amounts.append(int(tdsplit[2]))
	amounts.append(int(tdsplit[1]))
	amounts.append(int(tdsplit[0]))
	if len(td) == 3:
		amounts.append(int(td[0])%365)
		amounts.append(int(td[0])//365)

	word_amount = [(words[i], amount) for i, amount in enumerate(amounts) if amount]
	word_amount.reverse()
	
	answer = ""
	for ind, word in enumerate(word_amount):
		answer += f"{word[1]} {word[0]+plural(word[1])}"
		if ind+1 == len(word_amount)-1:
			answer += " and "
		elif ind != len(word_amount)-1:
			answer += ", "
	return answer 

def plural(amount):
	if amount > 1:
		return 's'
	return ''

print(format_duration(90461))
