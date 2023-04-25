# User function Template for python3
import math


class Solution:
    def primeDivision(self, N):
        # code here
        prime = [1] * (N + 1)
        prime[0] = prime[1] = 0
        for i in range(2, int(math.sqrt(N))+1):
            if prime[i]:
                for j in range(i * i, N+1, i):
                    prime[j] = 0

        ans = [-1, -1]
        for i in range(2, N//2+1):
            if prime[i] and prime[N-i]:
                return [i, N-i]

        return ans


# {
 # Driver Code Starts
# Initial Template for Python 3
if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        p1, p2 = ob.primeDivision(N)
        print(p1, end=" ")
        print(p2)
# } Driver Code Ends
