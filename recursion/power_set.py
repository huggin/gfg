# User function Template for python3


class Solution:
    def AllPossibleStrings(self, s):
        # Code here
        ans = []
        s = [c for c in s]
        n = len(s)
        curr = []

        def f(k):
            if k == n:
                ans.append("".join(curr))
                return
            curr.append(s[k])
            f(k + 1)
            curr.pop()
            f(k + 1)

        f(0)
        ans.sort()
        return ans[1:]


# {
# Driver Code Starts

# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s = input()
        ob = Solution()
        ans = ob.AllPossibleStrings(s)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
