import random
import string

charlist = string.ascii_letters
with open("testfile", 'a') as f:
    for i in range(1000):
        random_string = ""
        for i in range(50):
            random_char = random.choice(charlist)
            random_string += random_char
        
        random_marker = []
        for j in range(5):
            random_mark = random.choice(charlist)
            random_marker.append(random_mark)

        f.write(f"\n\"{random_string}\"|{random_marker}")