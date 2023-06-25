import math

def is_interesting(number, awesome_phrases):
    if len(str(number)) < 3 and number < 98:
        return 0
    
    rankings = []
    all_zeros = lambda x, _: set(str(x)[1:]) == {"0"}
    same_number = lambda x, _: len(set(str(x))) == 1

    rankings.append(find_ranking(number, all_zeros, 0))
    rankings.append(find_ranking(number, same_number, 0))
    
    rankings.append(find_ranking(number, is_incrementing, 0))
    rankings.append(find_ranking(int(str(number)[::-1]), is_incrementing, 1)) #need to pass in another parameter for setting 0 at start or end

    rankings.append(find_ranking(number, palindrome, 0))

    rankings.append(find_ranking(number, lambda x, _: x in awesome_phrases, 0))
    return max(rankings)

def is_incrementing(number, pos):
    if pos == 0:
        nums = [1,2,3,4,5,6,7,8,9,0]
    else:
        nums = [0,1,2,3,4,5,6,7,8,9]
    strnum = str(number)
    for i in range(len(strnum)-1):
        if nums.index(int(strnum[i])) != nums.index(int(strnum[i+1])) - 1:
            return False
    return True

def palindrome(number, _):
    strnum = str(number)
    first_half = strnum[:math.floor(len(strnum)/2)]
    second_half = strnum[math.ceil(len(strnum)/2):]
    if first_half == second_half[::-1]:
        return True
    
    return False

def find_ranking(number, function, i):
    if function(number, i):
        return 2
    elif function(number+1, i) or function(number+2, i):
        return 1
    else:
        return 0


print(is_interesting(11111111, [1111]))
