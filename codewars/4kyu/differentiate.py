# https://www.codewars.com/kata/566584e3309db1b17d000027/train/python
import re

def differentiate(equation: str, point: float) -> float:
    ans = 0
    equation.replace(" ","") #remove whitespace so the regex works properly

    regex_pattern = r"([+-]?\d*)x(\^?\d*)"
    terms = re.findall(regex_pattern, equation)
    for term in terms:
        if term:
            ans += solve(term, point)
    return ans

def solve(subequation: tuple, point: float) -> float:
    ans = 0

    first_half = subequation[0]
    second_half = subequation[1]

    if not first_half in ['+', '-', '']: #need to account for coefficients of 1 and -1
        ans = int(first_half)
    else:
        ans = -1 if first_half == '-' else 1
        
    if second_half: # if there is no exponent, stop here
        second_half = second_half[1:] #ignore the ^ to just get the number
        ans *= int(second_half)
        ans *= point**(int(second_half)-1)

    return ans



print(differentiate("x^2-x", 3))

