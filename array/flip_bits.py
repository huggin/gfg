# User function Template for python3


class Solution:
    def maxOnes(self, a, n):
        # Your code goes here
        ans = 0
        zero, one = 0, 0
        for c in a:
            if c == 0:
                zero += 1
            else:
                one += 1
                zero -= 1
            ans = max(ans, zero)
            if zero < 0:
                zero = 0
        return ans + one


# {
# Driver Code Starts
# Initial Template for Python 3


def main():
    T = int(input())

    while T > 0:
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.maxOnes(a, n))

        T -= 1


if __name__ == "__main__":
    main()


# } Driver Code Ends
