# User function Template for python3


class Solution:
    def removeKdigits(self, S, K):
        # code here
        s = []
        for c in S:
            while len(s) > 0 and s[-1] > c and K > 0:
                s.pop()
                K -= 1
            s.append(c)

        while K > 0:
            s.pop()
            K -= 1

        start = len(s)
        for i in range(len(s)):
            if s[i] != "0":
                start = i
                break

        if start == len(s):
            return "0"
        return "".join(s[start:])


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        S = input()
        K = int(input())

        obj = Solution()

        ans = obj.removeKdigits(S, K)

        print(ans)


# } Driver Code Ends
