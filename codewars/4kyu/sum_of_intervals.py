# https://www.codewars.com/kata/52b7ed099cdc285c300001cd/train/python

def sum_of_intervals(intervals):
    ans = merge_intervals(intervals)

    # now loop through ans and join any intervals which you can.
    ans = merge_intervals(ans)

    return sum(abs(x[1]-x[0]) for x in ans)

def merge_intervals(arr):
    ans = []
    for interval in arr:
        if not ans:
            ans.append(interval)
        else:
            ans = ammend_interval(ans, interval)
    return ans

def ammend_interval(ans, interval):
    print(f"{ans} --> {interval}")
    
    changed = False
    for i,a in enumerate(ans):
        if is_overlap(a, interval):
            ans[i] = [min(interval[0], a[0]), max(interval[1], a[1])] # update the value to the new overlap
            changed = True
            break # it overlaps one of them so we can just stop here. This fixes itself when you loop a second time.
   
    if not changed:
        ans.append(interval)  # the interval is new, so add it to the array

    return ans

def is_overlap(a, b):
    if b[0] < a[0] and b[1] < a[0]:
        return False
    if b[0] > a[1] and b[1] > a[1]:
        return False
    return True


print("-------------")
print(sum_of_intervals([(1, 4), (0, 3)]))
print("-------------")
print(sum_of_intervals([(1, 4), (0, 4)]))
print("-------------")
print(sum_of_intervals([(1, 4), (0, 5)]))
print("-------------")

print(sum_of_intervals([(1, 4), (1, 3)]))
print("-------------")
print(sum_of_intervals([(1, 4), (1, 4)]))
print("-------------")
print(sum_of_intervals([(1, 4), (1, 5)]))

print("-------------")
print(sum_of_intervals([(1, 4), (2, 3)]))
print("-------------")
print(sum_of_intervals([(1, 4), (2, 4)]))
print("-------------")
print(sum_of_intervals([(1, 4), (2, 5)]))
print("-------------")

print(sum_of_intervals([(1, 4), (4, 7)]))
print("-------------")

print(sum_of_intervals([(1, 4), (-3, 1)]))
print("-------------")

print(sum_of_intervals([
   [1,5],
   [10, 20],
   [1, 6],
   [16, 19],
   [5, 11]
]))
print("-------------")
