# User function Template for python3
import re


class Solution:
    def removeComments(self, code):
        # your code here
        pat = r"//.*\\n"
        code = re.sub(pat, "", code)
        pat = r"/\*.*\*/"
        code = re.sub(pat, "", code, re.MULTILINE)
        return code


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for tc in range(t):
        s = input()
        ob = Solution()
        print(ob.removeComments(s))

    # Contributed By: Pranay Bansal
# } Driver Code Ends
