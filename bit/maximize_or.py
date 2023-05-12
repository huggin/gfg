# User function Template for python3
class Solution:
    def getCount(self, X):
        # code here
        cnt = 0
        for i in range(31):
            if X >= (1 << i):
                if X & 1 << i:
                    cnt += 1

        return X - 2**cnt + 1


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        X = input()
        X = int(X)

        ob = Solution()
        print(ob.getCount(X))
# } Driver Code Ends
