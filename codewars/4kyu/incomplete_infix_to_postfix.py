#https://www.codewars.com/kata/52e864d1ffb6ac25db00017f/train/python

def to_postfix (infix):
    operators = []
    ans = ""

    for e in infix:
        #print(e)
        if is_operand(e):
            ans += e
            continue
        elif is_operator(e):
            if not operators:
                operators.append(e)
                continue
            # now we know its an operator and the array isn't empty
            o = operators[-1] #last element in list
            p = precedence(e, o)
            if p == 1: # e > o
                operators.append(e)
            elif p == -1: # e < o
                while operators and precedence(e, operators[-1]) == -1:
                    ans += operators.pop()
                operators.append(e)
            else: # e == o
                if e == "^":
                    while operators and precedence(e, operators[-1]) == -1:
                        ans += operators.pop()
                operators.append(e)
                
        elif e == "(":
            operators.append(e)
        elif e == ")":
            while operators[-1] != "(":
                ans += operators.pop()
            operators.pop() # pop the (

    while operators:
        ans += operators.pop()
    
    return ans


def is_operator(e):
    return e in "+-*/^"

def is_operand(e):
    return e in "0123456789"

def precedence(a, b):
    '''
    1  - a > b
    0  - a == b
    -1 - a < b
    '''
    operators = "+-*/^()"
    precedence = [1,1,2,2,3,4,4]
    if precedence[operators.index(a)] > precedence[operators.index(b)]:
        return 1
    elif precedence[operators.index(a)] == precedence[operators.index(b)]:
        return 0
    else:
        return -1

print(to_postfix("2+7*5"), "  275*+")
print(to_postfix("3*3/(7+1)"), "  33*71+/")
print(to_postfix("5+(6-2)*9+3^(7-1)"), "  562-9*+371-^+")
print(to_postfix("(5-4-1)+9/5/2-7/1/7"), "  54-1-95/2/+71/7/-")
print(to_postfix("1^2^3"), "  123^^")


