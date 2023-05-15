# User function Template for python3


class Solution:
    def solve(self, s, k):
        ans = 0
        n = len(s)
        cnt = 0
        j = 0
        for i in range(n):
            if s[i] == "1":
                cnt += 1
            while j < n and cnt > k:
                if s[j] == "1":
                    cnt -= 1
                j += 1
            ans += i - j + 1
        return ans

    def countOfSubstringWithKOnes(self, S, K):
        # code here
        if K == 0:
            return self.solve(S, K)
        return self.solve(S, K) - self.solve(S, K - 1)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        inp = input().strip().split(" ")
        s = inp[0]
        k = int(inp[1])
        ob = Solution()
        print(ob.countOfSubstringWithKOnes(s, k))
# } Driver Code Ends
