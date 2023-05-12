# User function Template for python3


class Solution:
    def solve(self, k, n, curr, prev=0):
        if k == n:
            self.ans.append(curr)
            return

        for i in range(prev + 1, 10):
            curr = curr * 10 + i
            self.solve(k + 1, n, curr, i)
            curr = curr // 10

    def increasingNumbers(self, N):
        # code here
        self.ans = [] if N != 1 else [0]
        self.solve(0, N, 0)
        return self.ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        ob = Solution()
        ans = ob.increasingNumbers(N)
        for num in ans:
            print(num, end=" ")
        print()
# } Driver Code Ends
