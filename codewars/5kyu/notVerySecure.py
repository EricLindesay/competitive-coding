from re import search

def alphanumeric(password):
    regex = "^[a-zA-Z0-9]{1,}$"
    return bool(search(regex, password))

print(alphanumeric("12"))