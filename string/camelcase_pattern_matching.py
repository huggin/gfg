# User function Template for python3


class Solution:
    def match(self, s, p):
        i, j = 0, 0
        n = len(s)
        m = len(p)
        while i < n and j < m:
            if s[i].isupper():
                if s[i] != p[j]:
                    return False
                j += 1
            i += 1

        return j == m

    def CamelCase(self, N, Dictionary, Pattern):
        # code here
        ans = []
        for a in Dictionary:
            if self.match(a, Pattern):
                ans.append(a)

        return ans if len(ans) > 0 else [-1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        Dictionary = list(map(str, input().split()))
        Pattern = input()
        ob = Solution()
        ans = ob.CamelCase(N, Dictionary, Pattern)
        ans.sort()
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
