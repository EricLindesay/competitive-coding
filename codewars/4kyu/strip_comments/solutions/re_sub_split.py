import re


def strip_comments(string, markers):
    if not markers:
        return string

    ans = []
    splitted = string.split('\n')  # split based on \n
    
    mark_string = ''.join(markers).replace("^", "\^").replace("-", "\-")

    for s in splitted:  
        pattern = f"\s*[{mark_string}].*"  # optional whitespace then any marker then any other character
        res = re.sub(pattern, '', s)
        ans.append(res)
    
    return '\n'.join(ans)


if __name__ == "__main__":
    print(strip_comments("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"]))

