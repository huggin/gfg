# User function Template for python3


class Solution:
    def findNoOfEdges(self, C, F):
        # code here
        return (int(C) + int(F) - 2) % 10


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        C, F = map(str, input().split())

        ob = Solution()
        print(ob.findNoOfEdges(C, F))
# } Driver Code Ends
