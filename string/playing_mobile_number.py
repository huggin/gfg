# User function Template for python3
import re


class Solution:
    def is_valid(self, s):
        # Code here
        return 1 if re.match("^(0|91)?[789]{1}[0-9]{9}$", s) else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s = input()
        ob = Solution()
        ans = ob.is_valid(s)
        print(ans)

# } Driver Code Ends
