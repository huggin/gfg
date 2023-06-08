# User function Template for python3


class Solution:
    def solve(self, s, k, n, marked, curr):
        if k == n:
            self.ans.add("".join(curr))
            return

        for i in range(n):
            if marked[i] == 0:
                curr.append(s[i])
                marked[i] = 1
                self.solve(s, k + 1, n, marked, curr)
                marked[i] = 0
                curr.pop()

    def find_permutation(self, S):
        # Code here
        s = list(c for c in S)
        s.sort()
        n = len(s)
        marked = [0] * n
        self.ans = set()
        self.solve(s, 0, n, marked, [])
        return sorted(self.ans)


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        S = input()
        ob = Solution()
        ans = ob.find_permutation(S)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
