# User function Template for python3

class Solution:
    def countSpecialNumbers(self, N, arr):
        # Code here
        ma = max(arr)
        mark = [-1] * (ma + 1)
        for a in arr:
            if mark[a] == -1:
                mark[a] = 1
                for i in range(a+a, ma+1, a):
                    mark[i] = 0
            elif mark[a] == 1:
                mark[a] = 0

        ans = 0
        for a in arr:
            if mark[a] == 0:
                ans += 1

        return ans

# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':

    T = int(input())
    while T > 0:
        N = int(input())
        arr = [int(i) for i in input().split()]
        ob = Solution()
        print(ob.countSpecialNumbers(N, arr))

        T -= 1
# } Driver Code Ends
