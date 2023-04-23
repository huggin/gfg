# User function Template for python3

class Solution:
    def countMinOperations(self, arr, n):
        # code here
        ans = 0
        add = 0
        for i in range(n):
            double = 0
            while arr[i] > 0:
                if arr[i] % 2:
                    arr[i] -= 1
                    add += 1
                else:
                    arr[i] //= 2
                    double += 1

            ans = max(ans, double)

        return ans + add
# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countMinOperations(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
