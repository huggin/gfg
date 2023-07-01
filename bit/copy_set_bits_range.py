# User function Template for python3


class Solution:
    def setSetBit(self, x, y, l, r):
        # code here
        return x | ((1 << r) - (1 << l - 1)) & y


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = input().split()
        x = int(arr[0])
        y = int(arr[1])
        l = int(arr[2])
        r = int(arr[3])

        ob = Solution()
        print(ob.setSetBit(x, y, l, r))
# } Driver Code Ends
