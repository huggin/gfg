# User function Template for python3


class Solution:
    def numOfPairs(self, X, Y, N):
        # code here
        dict1, dict2 = {}, {}
        equal = {}
        ans = 0
        for i in range(N):
            temp = dict1.get(X[i], 0)
            ans += temp
            dict1[X[i]] = temp + 1
            temp = dict2.get(Y[i], 0)
            ans += temp
            dict2[Y[i]] = temp + 1
            d = X[i] * (10**9 + 1) + Y[i]
            temp = equal.get(d, 0)
            ans -= 2 * temp
            equal[d] = temp + 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        X = list(map(int, input().split()))
        Y = list(map(int, input().split()))

        ob = Solution()
        print(ob.numOfPairs(X, Y, N))
# } Driver Code Ends
