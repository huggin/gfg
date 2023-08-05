# User function Template for python3


class Solution:
    def permutation(self, s):
        ans = []
        n = len(s)
        li = list(c for c in s)

        def dfs(k):
            if k == n:
                ans.append("".join(li))
                return
            for i in range(k, n):
                li[i], li[k] = li[k], li[i]
                dfs(k + 1)
                li[i], li[k] = li[k], li[i]

        dfs(0)
        ans.sort()
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        s = input()
        ob = Solution()
        ans = ob.permutation(s)
        for i in ans:
            print(i, end=" ")
        print()

        T -= 1
# } Driver Code Ends
