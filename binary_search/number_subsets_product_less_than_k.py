# User function Template for python3
import bisect


class Solution:
    def calc(self, a, lo, hi, K):
        ans = []
        for i in range(1, 1 << (hi - lo)):
            temp = 1
            for j in range(lo, hi):
                if (1 << (j - lo)) & i:
                    temp *= a[j]
            if temp <= K:
                ans.append(temp)

        return ans

    def numOfSubsets(self, arr, N, K):
        # code here
        left = self.calc(arr, 0, N // 2, K)
        right = self.calc(arr, N // 2, N, K)
        left.sort()
        ans = len(left) + len(right)
        for a in right:
            idx = bisect.bisect(left, K // a)
            ans += idx

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        K = int(input())

        ob = Solution()
        print(ob.numOfSubsets(arr, N, K))
# } Driver Code Ends
