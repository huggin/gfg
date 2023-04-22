# User function Template for python3

class Solution:
    def findSmallest(self, arr, n):
        # code here
        ans = 1
        for a in arr:
            if a > ans:
                return ans
            ans += a

        return ans

# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.findSmallest(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
