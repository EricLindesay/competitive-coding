# https://www.codewars.com/kata/56a1c63f3bc6827e13000006/train/python


def smaller(arr):
    ans = []
    counts = {}

    for a in arr[::-1]:  # loop backwards
        answer = 0
        for key in counts:
            if key < a:
                answer += counts[key]

        counts[a] = counts.get(a, 0) + 1
        
        print(counts)
        ans.append(answer)

    return ans[::-1] 

if __name__ == "__main__":
    print(smaller([5,3,9,2,1,1]))

