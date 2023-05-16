# User function Template for python3


class Solution:
    def isPossible(self, n, m, s):
        # code here
        i, j = 0, 0
        l, r, u, d = 0, 0, 0, 0
        for c in s:
            if c == "L":
                j -= 1
            elif c == "R":
                j += 1
            elif c == "D":
                i -= 1
            else:
                i += 1

            l = min(l, j)
            r = max(r, j)
            d = min(d, i)
            u = max(u, i)

        return 1 if r - l < m and u - d < n else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n, m = [int(x) for x in input().split()]
        s = input()

        ob = Solution()
        print(ob.isPossible(n, m, s))
# } Driver Code Ends
