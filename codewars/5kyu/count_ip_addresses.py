def ips_between(start, end):
    sstart = start.split('.')
    send = end.split('.')
    sum = 0
    for i in range(len(sstart)):
        diff = int(send[i])-int(sstart[i])
        sum += diff * (256**(3-i))
    return sum


print(ips_between("10.0.0.0", "10.1.0.0"))
