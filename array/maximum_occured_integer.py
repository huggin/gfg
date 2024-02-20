# User function Template for python3


class Solution:
    # Complete this function
    # Function to find the maximum occurred integer in all ranges.
    def maxOccured(self, L, R, N, maxx):
        ##Your code here
        m = max(R)
        cnt = [0] * (m + 2)
        for i in range(N):
            cnt[L[i]] += 1
            cnt[R[i] + 1] -= 1

        ans = 0
        ma = cnt[0]
        for i in range(1, m + 1):
            cnt[i] += cnt[i - 1]
            if cnt[i] > ma:
                ma = cnt[i]
                ans = i

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


import math

A = [0] * 1000000


def main():

    T = int(input())

    while T > 0:

        global A
        A = [0] * 1000000

        N = int(input())

        L = [int(x) for x in input().strip().split()]
        R = [int(x) for x in input().strip().split()]

        maxx = max(R)
        ob = Solution()
        print(ob.maxOccured(L, R, N, maxx))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
