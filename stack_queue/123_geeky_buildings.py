# User function Template for python3

class Solution:
    def recreationalSpot(self, arr, n):
        # Your code goes here
        mi = -1
        s = []
        for a in reversed(arr):
            if a < mi:
                return True
            while len(s) > 0 and s[-1] < a:
                mi = s[-1]
                s.pop()
            s.append(a)

        return False


# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    tcs = int(input())
    for _ in range(tcs):
        n = int(input())
        arr = [int(x) for x in input().split()]
        ob = Solution()
        if ob.recreationalSpot(arr, n):
            print("True")
        else:
            print("False")


# } Driver Code Ends
