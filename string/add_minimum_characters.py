# User function Template for python3


class Solution:
    def solve(self, s):
        s += "%"
        n = len(s)
        next = [0] * n
        j = -1
        for i in range(n):
            if i == 0:
                next[i] = -1
            elif s[i] != s[j]:
                next[i] = j
            else:
                next[i] = next[j]
            while j >= 0 and s[i] != s[j]:
                j = next[j]
            j += 1
        return next

    def addMinChar(self, str1):
        # code here
        s = str1 + "$" + str1[::-1]
        next = self.solve(s)
        return len(str1) - next[-1]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        str1 = input()

        ob = Solution()
        print(ob.addMinChar(str1))

# } Driver Code Ends
# User function Template for python3
