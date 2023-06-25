# https://www.codewars.com/kata/52996b5c99fdcb5f20000004/train/python
# problem understanding what it wants

def runoff(voters):
    votes = {"temp": 1, "temp2": 2}
    
    while len(votes) > 1:
        votes = {}
        for voter in voters:
            for pos, val in enumerate(voter):
                score = len(voter)-pos
                if val not in votes.keys():
                    votes[val] = score
                else:
                    votes[val] += 1*score
        
        print(votes)

        # If the first-place candidate has more than half the total votes, they win.
        total = sum(votes.values())
        for vote in votes.keys():
            if votes[vote] > total*0.5:
                return vote

        # lower score == better
        # Otherwise, find the candidate who got the least votes and remove them from each person's voting list.
        # In case of a tie for least, remove all of the tying candidates.
        tying = [list(votes)[0]]
        for vote in votes.keys():
            if votes[vote] == votes[tying[0]]:
                tying.append(vote)
            elif votes[vote] < votes[tying[0]]:
                tying = [vote]
        
        if len(tying) == len(votes.keys()):
            return None
        
        new_voters = []
        for voter in voters:
            row = []
            for val in voter:
                if val not in tying:
                    row.append(val)
            new_voters.append(row)
        
        voters = new_voters
        print(voters)

    return None


voters = [["a", "c", "d", "e", "b"],
         ["e", "b", "d", "c", "a"],
         ["d", "e", "c", "a", "b"],
         ["c", "e", "d", "b", "a"],
         ["b", "e", "a", "c", "d"]]

ans = runoff(voters)
print(ans)

