# User function Template for python3


class Solution:
    def findWinner(self, n, A):
        # code here
        now = 0
        for a in A:
            now ^= a

        if now == 0:
            return 1
        return 2 if n % 2 else 1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        A = input().split()
        for itr in range(n):
            A[itr] = int(A[itr])

        ob = Solution()
        print(ob.findWinner(n, A))

# } Driver Code Ends
