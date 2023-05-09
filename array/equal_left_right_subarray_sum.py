# User function Template for python3


class Solution:
    # Complete this function

    # Function to find equilibrium point in the array.
    def equalSum(self, A, N):
        # Your code here
        s = sum(A)
        pre = 0
        for i in range(N):
            if pre == s - A[i] - pre:
                return i + 1
            pre += A[i]

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        N = int(input())

        A = [int(x) for x in input().strip().split()]
        ob = Solution()

        print(ob.equalSum(A, N))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
