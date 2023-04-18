# User function Template for python3


class Solution:
    def convert(self, Str, n):
        # code here
        if n == 1:
            return Str
        ans = [[] for _ in range(n)]
        i = 0
        step = 1
        for c in Str:
            ans[i].append(c)
            i += step
            if i == n - 1:
                step = -1
            elif i == 0:
                step = 1

        return "".join("".join(ans[i]) for i in range(n))


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        Str = input()
        n = int(input())

        solObj = Solution()

        print(solObj.convert(Str, n))
# } Driver Code Ends
