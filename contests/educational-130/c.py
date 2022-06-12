n = int(input())

while n > 0:
    n -= 1
    
    str_len = int(input())
    str1 = list(input())
    str2 = list(input())

    print(f"\n\n{str_len}")
    swapped = True
    while swapped:
        swapped = False
        for i in range(str_len-1):
            if i == 3:
                print("OI")
                print(str1[i], str1[i+1], str2[i])
            if str1[i] == "a" and str1[i+1] == "b" and str2[i] == "b":
                str1[i], str1[i+1] = str1[i+1], str1[i]
                swapped = True
                print("swap ab")
            if str1[i] == "b" and str1[i+1] == "c" and str2[i] == "c":
                str1[i], str1[i+1] = str1[i+1], str1[i]
                print("swap bc")
                swapped = True    
        print(''.join(str1), ''.join(str2))
    print("YES" if str1==str2 else "NO")
