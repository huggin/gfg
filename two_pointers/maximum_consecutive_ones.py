# User function Template for python3


class Solution:
    def longestOnes(self, n, a, k):
        # Code here
        if a.count(0) <= k:
            return n
        i, j = 0, 0
        ans = 0
        used = 0
        while i < n:
            if a[i] == 0:
                if used < k:
                    used += 1
                else:
                    ans = max(ans, i - j)
                    while j <= i:
                        if a[j] == 0:
                            used -= 1
                        j += 1
                        if used < k:
                            break
                    i -= 1
            i += 1
        ans = max(ans, i - j)
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        k = int(input())
        ob = Solution()
        print(ob.longestOnes(n, a, k))
# } Driver Code Ends``
