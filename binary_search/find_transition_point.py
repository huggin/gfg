import bisect


class Solution:
    def transitionPoint(self, arr, n):
        # Code here
        idx = bisect.bisect_left(arr, 1)
        return -1 if idx == n else idx


# {
# Driver Code Starts
# driver code
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.transitionPoint(arr, n))

# } Driver Code Ends
