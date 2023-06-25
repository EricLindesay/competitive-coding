# https://www.codewars.com/kata/56a1c63f3bc6827e13000006/train/python


def smaller(arr):
    # sort the right sublist and count how many are smaller than it.
    ans = [0 for i in arr]
    for ind, num in enumerate(arr):
        sublist = sorted(arr[ind+1:])
        for subnum in sublist:
            if num > subnum:
                ans[ind] += 1
            else:
                break
    return ans

if __name__ == "__main__":
    print(smaller([1,2,3]))

