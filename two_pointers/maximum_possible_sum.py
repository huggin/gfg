from collections import defaultdict


class Solution:
    def returnMaxSum(self, a, b, n):
        # Your code goes here
        ans = 0
        curr = 0
        d = defaultdict(int)
        j = 0
        for i in range(n):
            while j < i and d[a[i]] > 0:
                curr -= b[j]
                d[a[j]] -= 1
                j += 1
            curr += b[i]
            d[a[i]] = 1

            ans = max(ans, curr)
        return ans


# {
# Driver Code Starts
if __name__ == "__main__":

    t = int(input())
    for _ in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        b = list(map(int, input().split()))
        ob = Solution()
        ans = ob.returnMaxSum(a, b, n)
        print(ans)

# } Driver Code Ends
