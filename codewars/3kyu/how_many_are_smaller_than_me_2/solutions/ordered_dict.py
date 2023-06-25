# https://www.codewars.com/kata/56a1c63f3bc6827e13000006/train/python

from collections import OrderedDict


def smaller(arr):
    #counts = {}
    ans = []
    
    #counts[4] = counts.get(4,0)+1
    #counts[2] = counts.get(2,0)+1
    
    counts = OrderedDict()
    #counts = {}

    # could get a list of pairs to put before and list after.

    for ind, a in enumerate(arr[::-1]):  # loop backwards
        # if the value isn't in count, add it. Otherwise increment it.
        # then find how many values are less than it in the dictionary
        # add that value into ans.
        # when finding the place to insert it, you may as well add the values as well.
        # you must ensure that the dict keys are ordered    
        
        # try using an ordered dict
        seen = []
        # look for where to insert/get count
        insert_pos = None
        answer = 0

        for count_ind, key in enumerate(counts):
            print(counts)
            if key < a:
                answer += counts[key]
                seen.append((key, counts[key]))
                # delete the keys from the dict then add them back later
                del counts[key]  # instead of deleting, could just loop through moving each to front
            elif key > a:
                insert_pos = count_ind
                print("seen: ",seen)
                # insert into dict
                counts[a] = 0
                counts.move_to_end(a,last=False) # move to front.
                # Loop through seen backwards, adding it to front
                for s in seen[::-1]:
                    counts[s[0]] = s[1]
                    counts.move_to_end(s[0],last=False)
                break
            else:  
                # the key is already in the dictionary so increment
                break
        
        ans.append(answer)

        '''
        if insert_pos: # insert into end of dict
            counts[a] = 1
        else:
            counts[a] += 1
        '''
        counts[a] = counts.get(a, 0) + 1

    return ans[::-1] 

if __name__ == "__main__":
    print(smaller([5,3,9,2,1,1]))

