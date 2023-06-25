import string

def kebabize(input_str):
    ans = ""
    for char in input_str:
        if (c := char.lower()) not in string.ascii_lowercase:
            continue
        if char.isupper() and len(ans) > 0:
            ans += "-"
        ans += c

    return ans


print(kebabize("4CamelsHave3Humps"))
