# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3
from collections import Counter


class Solution:
    def isStraightHand(self, N, groupSize, hand):
        # Code here
        c = Counter()

        for a in hand:
            c[a] += 1

        for k in sorted(c):
            if c[k] == 0:
                continue
            for i in range(groupSize):
                c[k + i] -= 1
                if c[k + i] < 0:
                    return False

        return True


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, groupSize = list(map(int, input().split()))
        hand = list(map(int, input().split()))
        ob = Solution()
        res = ob.isStraightHand(N, groupSize, hand)
        print(res)
# } Driver Code Ends
