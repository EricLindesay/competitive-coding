def dirReduc(arr):
    # https://www.codewars.com/kata/550f22f4d758534c1100025a/train/python

    while (index := collision(arr)) != None:
        arr.pop(index)
        arr.pop(index)

    return arr

def collision(arr):
    for i in range(len(arr)-1):
        if arr[i] == "NORTH" and arr[i+1] == "SOUTH":
            return i
        elif arr[i] == "SOUTH" and arr[i+1] == "NORTH":
            return i
        elif arr[i] == "WEST" and arr[i+1] == "EAST":
            return i
        elif arr[i] == "EAST" and arr[i+1] == "WEST":
            return i
    return None

print(dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]))
