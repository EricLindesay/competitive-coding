def next_bigger(n):
    s = str(n)
    i = len(s) - 1
    ans = ""
    while i >= 1:
        if (int(s[i]) > int(s[i-1])):
            ans += s[i-1]
            ans += s[i]
            break
        i -= 1

    if ans == "": # Nothing was swapped
        return -1

    ans += s[:i-1]
    ans = ans[::-1]

    return int(ans)


print(next_bigger(234832))
