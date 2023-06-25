# https://www.codewars.com/kata/56a1c63f3bc6827e13000006/train/python

def smaller(arr):
    ans = [0 for i in arr]
    for ind, a in enumerate(arr):
        for b in arr[ind:]:
            if a > b:
                ans[ind] += 1
    return ans 

if __name__ == "__main__":
    print(smaller([98, 40, 66, 13, 18, 38, 38, 69, 36, 96, 57, 40, 64, 83, 47, 25, 15, 55, 60, 33, 94, 100, 68, 21, 79, 39, 20, 74, 75, 45, 70, 93, 18, 13, 21, 34, 17, 27, 10, 9, 53, 89, 0, 80, 100, 44, 100, 45, 20, 51]))

