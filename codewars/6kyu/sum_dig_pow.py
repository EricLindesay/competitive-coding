def sum_dig_pow(a, b): # range(a, b + 1) will be studied by the function
    ans = []
    for value in range(a, b+1):
        calc = sum([int(char)**(ind+1) for ind,char in enumerate(str(value))])
        if calc == value:
            ans.append(calc)

    return ans


print(sum_dig_pow(1, 100))

