# User function Template for python3


class Solution:
    def isProduct(self, arr, x):
        # code here
        s = set(arr)
        for a in arr:
            if x % a == 0 and x // a in s:
                return True
        return False


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        arr = list(map(int, input().strip().split()))
        x = int(input())
        ob = Solution()
        ans = ob.isProduct(arr, x)
        if ans:
            print("true")
        else:
            print("false")
        tc -= 1

        print("~")
# } Driver Code Ends
