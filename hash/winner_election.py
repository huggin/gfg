# User function Template for python3
from collections import Counter


class Solution:
    # Complete this function

    # Function to return the name of candidate that received maximum votes.
    def winner(self, arr, n):
        # Your code here
        # return the name of the winning candidate and the votes he recieved
        c = Counter(arr)
        winner, cnt = "", 0
        for k, v in c.items():
            if v > cnt or v == cnt and k < winner:
                cnt = v
                winner = k

        return [winner, cnt]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        n = int(input())
        arr = input().strip().split()

        result = Solution().winner(arr, n)
        print(result[0], result[1])
# } Driver Code Ends
