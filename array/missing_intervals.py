# User function Template for python3


class Solution:
    def printMissingIntervals(self, a, n):
        # code here
        sz = 100000
        m = [0] * sz
        for i in range(n):
            m[a[i]] = 1
        ans = []
        curr = 0
        while curr < sz:
            if m[curr] == 0:
                ans.append(curr)
                while curr < sz and m[curr] == 0:
                    curr += 1
                ans.append(curr - 1)
            curr += 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())

        a = list(map(int, input().split()))

        ob = Solution()
        l = ob.printMissingIntervals(a, n)

        for i in range(0, len(l), 2):
            if l[i] == l[i + 1]:
                print(l[i], end="")
            else:
                print(l[i], end="")
                print("-", end="")
                print(l[i + 1], end="")
            if i != len(l) - 2:
                print(",", end="")
        print()
# } Driver Code Ends
