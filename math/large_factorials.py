# User function Template for python3
import math


def fact(n):
    # Complete the function
    s = 0.0
    for i in range(1, n + 1):
        s += math.log10(i)

    ans = [0, 0]
    f = math.floor(s)
    p = s - f
    ans[0] = int(math.pow(10, p) + 1e-6)
    ans[1] = f
    return ans


# {
# Driver Code Starts
# Initial Template for Python 3


for _ in range(0, int(input())):
    n = int(input())
    ans = fact(n)
    print(*ans)


# } Driver Code Ends
