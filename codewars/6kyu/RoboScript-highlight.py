# https://www.codewars.com/kata/roboscript-number-1-implement-syntax-highlighting

def highlight(code: str):
    ans = ""
    prev_char = ""
    colours = { 
        'F': "pink",
        'L': "red",
        'R': "green",
        }
    numbers = [str(x) for x in range(0,10)]

    for chr in code:
        if chr in "()":
            ans += chr

        elif prev_char == chr or (chr in numbers and prev_char in numbers):
            ans = ans[:-7]+chr+ans[-7:]

        elif chr in numbers:
            ans += f"<span style=\"color: orange\">{chr}</span>"
        elif chr in ['F','L','R']:
            ans += f"<span style=\"color: {colours[chr]}\">{chr}</span>"
        prev_char = chr
    return ans

print(highlight("FFFRF5LF7"))

