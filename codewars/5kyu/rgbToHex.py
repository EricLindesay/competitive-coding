def rgb(r, g, b):
    ans = ""

    rgb = [r,g,b]
    rgb = map(check_bounds_and_fix, rgb)
    rgb = map(format_hex_string, rgb)

    for string in rgb:
        ans += string

    return ans.upper()

def check_bounds_and_fix(decimal: float):
    if decimal < 0:
        return 0
    if decimal > 255:
        return 255
    return round(decimal)

def format_hex_string(decimal: int):
    ans = ""
    if len(x := hex(decimal)[2:]) < 2:
        ans += "0"+x
    else:
        ans += x
    return ans


print(rgb(-1,255,255))
