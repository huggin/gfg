# User function Template for python3
class Solution:
    def getLastMoment(self, n, left, right):
        # code here
        ma = 0
        for a in left:
            ma = max(ma, a)
        for a in right:
            ma = max(ma, n - a)
        return ma


# {
# Driver Code Starts
# Initial Template for Python 3

# Main
if __name__ == "__main__":
    t = int(input())
    while t:
        t -= 1

        # Reading the length of the plank
        n = int(input().strip())

        # Reading positions of ants moving left
        left = [int(x) for x in input().strip().split()]

        # Reading positions of ants moving right
        right = [int(x) for x in input().strip().split()]

        ob = Solution()
        result = ob.getLastMoment(n, left, right)

        print(result)
        print("~")

# } Driver Code Ends
