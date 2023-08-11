# User function Template for python3
import bisect


class Solution:
    # Function to find length of longest increasing subsequence.
    def longestSubsequence(self, a, n):
        # code here
        ans = []
        for c in a:
            idx = bisect.bisect_left(ans, c)
            if idx == len(ans):
                ans.append(c)
            else:
                ans[idx] = c
        return len(ans)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        a = [int(x) for x in input().split()]
        ob = Solution()
        print(ob.longestSubsequence(a, n))
# } Driver Code Ends
