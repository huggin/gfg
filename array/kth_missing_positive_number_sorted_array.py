# User function Template for python3
class Solution:
    def kthMissing(self, arr, k):
        # code here
        b = 0
        cnt = 0
        for a in arr:
            if cnt + a - b - 1 >= k:
                return b + k - cnt
            cnt += a - b - 1
            b = a

        return k - cnt + b


# {
# Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == "__main__":
    t = int(input())
    while t:
        t -= 1
        A = [int(x) for x in input().strip().split()]
        nd = [int(x) for x in input().strip().split()]
        D = nd[0]
        ob = Solution()
        ans = ob.kthMissing(A, D)
        print(ans)
        print("~")

# } Driver Code Ends
