# User function Template for python3
class Solution:
    def onesComplement(self, S, N):
        # code here
        s = ["1" if c == "0" else "0" for c in S]
        return "".join(s)


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        S = input()

        ob = Solution()
        print(ob.onesComplement(S, N))
# } Driver Code Ends
