# User function Template for python3
class Solution:
    def isSumString(self, s: str) -> int:
        # code here
        n = len(s)
        for i in range(1, n):
            x = int(s[:i])
            for j in range(i + 1, n):
                y = int(s[i:j])
                k = j
                while k < n:
                    z = x + y
                    sz = str(z)
                    if sz != s[k : k + len[sz]]:
                        break
                    x = y
                    y = z
                    k = k + len[sz]
                if k == n:
                    return 1
                else:
                    break
        return 0


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = str(input())

        ob = Solution()

        print(ob.isSumString(S))
# } Driver Code Ends
