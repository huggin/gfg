# User function Template for python3
from collections import defaultdict


class Solution:
    def extraCount(self, s):
        # code here
        d = defaultdict(int)
        for c in s:
            d[c] += 1
        n = len(s)
        return [
            str(n // 4 - d["R"]),
            str(n // 4 - d["B"]),
            str(n // 4 - d["Y"]),
            str(n // 4 - d["G"]),
        ]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()

        ob = Solution()
        ans = ob.extraCount(s)
        print("R" + ans[0] + "B" + ans[1] + "Y" + ans[2] + "G" + ans[3])
# } Driver Code Ends
