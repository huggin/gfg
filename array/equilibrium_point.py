# User function Template for python3


class Solution:
    # Complete this function

    # Function to find equilibrium point in the array.
    def equilibriumPoint(self, A, N):
        # Your code here
        if N == 1:
            return 1
        pre_sum = [0] * N
        pre_sum[0] = A[0]
        for i in range(1, N):
            pre_sum[i] = pre_sum[i - 1] + A[i]

        for i in range(1, N - 1):
            if pre_sum[i - 1] == pre_sum[N - 1] - pre_sum[i]:
                return i + 1
        return -1


# {
# Driver Code Starts
# Initial Template for Python 3

import math


def main():
    T = int(input())

    while T > 0:
        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob = Solution()

        print(ob.equilibriumPoint(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
