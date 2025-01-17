# User function Template for python3


class Solution:
    def isPatternPresent(self, S, P):
        # code here
        if P[0] == "^" and P[-1] == "$":
            return 1 if S == P[1:-1] else 0
        if P[0] == "^":
            return 1 if S.startswith(P[1:]) else 0
        if P[-1] == "$":
            return 1 if S.endswith(P[0:-1]) else 0
        return 1 if S.find(P) != -1 else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        P = input()
        S = input()

        ob = Solution()
        print(ob.isPatternPresent(S, P))
        print("~")
# } Driver Code Ends
