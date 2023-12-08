# User function Template for python3


class Solution:
    def minNumber(self, arr, n):
        # code here
        s = sum(arr)

        def prime(a):
            i = 2
            while i * i <= a:
                if a % i == 0:
                    return False
                i += 1

            return True

        i = s
        while True:
            if prime(i):
                return i - s
            i += 1

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    n = int(input())
    #    l=list(map(int,input().split()))
    #    n=l[0]
    #    m=l[1]
    a = list(map(int, input().split()))
    # k = int(input())
    #  b = list(map(int, input().split()))
    ob = Solution()
    ans = ob.minNumber(a, n)
    print(ans)

# } Driver Code Ends
