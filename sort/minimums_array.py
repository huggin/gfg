# User function Template for python3


class Solution:
    def getMin(self, A, B, n):
        # Your code goes here
        if n == 1:
            return -1
        a = []
        b = []
        for i in range(n):
            a.append((A[i], i))
            b.append((B[i], i))

        a.sort()
        b.sort()
        if a[0][1] != b[0][1]:
            return a[0][0] + b[0][0]
        else:
            return min(a[0][0] + b[1][0], a[1][0] + b[0][0])


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        b = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.getMin(a, b, n))

        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
