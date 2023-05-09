class Solution:
    def findMax(self, n, m, a, b, c):
        # Your code goes here
        ans = [0] * (n + 1)
        for i in range(m):
            ans[a[i]] += c[i]
            ans[b[i] + 1] -= c[i]

        for i in range(1, n + 1):
            ans[i] += ans[i - 1]

        return max(ans)


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        l = list(map(int, input().split()))
        n = l[0]
        m = l[1]
        a = []
        b = []
        c = []
        for j in range(0, m):
            v = list(map(int, input().split()))
            a.append(v[0])
            b.append(v[1])
            c.append(v[2])
        ob = Solution()
        print(ob.findMax(n, m, a, b, c))
# } Driver Code Ends
