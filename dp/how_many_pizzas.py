# User function Template for python3


class Solution:
    def getCommon(self, arr1, arr2):
        n = len(arr1)
        m = len(arr2)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        ans = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if arr1[i - 1] == arr2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
                ans = max(ans, dp[i][j])
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


def main():

    T = int(input())

    while T > 0:

        arr1 = [int(x) for x in input().strip().split()]
        arr2 = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.getCommon(arr1, arr2))

        T -= 1

        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
