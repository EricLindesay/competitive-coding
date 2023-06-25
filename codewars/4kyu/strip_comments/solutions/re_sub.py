import re


def strip_comments(string, markers):
    if not markers:
        return string

    mark_string = ''.join(markers).replace("-", "\-").replace("^", "\^")

    pattern = f"[^\S\n]*[{mark_string}][^\n]*"
    string = re.sub(pattern, '', string)
    
    return string


if __name__ == "__main__":
    print(strip_comments('\tavocados\n#\n- watermelons ^ lemons !\noranges - watermelons bananas =\navocados , cherries avocados', ['?', '#', ',', '-']))
        