# User function Template for python3
import math


class Solution:
    def kThSmallestFactor(self, N, K):
        # code here
        n = int(math.sqrt(N)) + 1
        factor = []
        for i in range(1, n):
            if N % i == 0:
                factor.append(i)
                if N // i != i:
                    factor.append(N // i)

        factor.sort()
        if K > len(factor):
            return -1
        return factor[K-1]

# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, K = map(int, input().split())

        ob = Solution()
        print(ob.kThSmallestFactor(N, K))
# } Driver Code Ends
