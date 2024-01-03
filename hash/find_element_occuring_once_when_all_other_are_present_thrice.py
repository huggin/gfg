# User function Template for python3
from collections import Counter


class Solution:
    def singleElement(self, arr, N):
        # code here
        return Counter(arr).most_common()[-1][0]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))

        ob = Solution()
        print(ob.singleElement(arr, N))
# } Driver Code Ends
