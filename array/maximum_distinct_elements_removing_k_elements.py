# User function Template for python3
from collections import Counter


class Solution:
    def maxDistinctNum(self, arr, k):
        # Complete the function
        c = Counter(arr)
        for v in c.values():
            if k >= v - 1:
                k -= v - 1
        return len(c) - k


# {
# Driver Code Starts
if __name__ == "__main__":
    import heapq

    tc = int(input().strip())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        k = int(input().strip())
        ob = Solution()
        print(ob.maxDistinctNum(arr, k))
        tc -= 1
        print("~")

# } Driver Code Ends
