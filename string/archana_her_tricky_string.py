# User function Template for python3


class Solution:
    def findString(self, s):
        # code here
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord("A")] += 1

        ans = ""
        diff = 2000
        for i in range(25, -1, -1):
            if cnt[i] == 0:
                continue
            for j in range(1, 26):
                c = ""
                for k in range(i, -1, -j):
                    if cnt[k] == 0:
                        break
                    c += chr(ord("A") + k)
                if len(c) > len(ans) or len(c) == len(ans) and diff > j:
                    ans = c
                    diff = j

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        s = input()

        solObj = Solution()

        print(solObj.findString(s))
# } Driver Code Ends
