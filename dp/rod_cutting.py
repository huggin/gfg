#User function Template for python3

class Solution:
    def cutRod(self, price, n):
        #code here
        dp = [-1] * (n)
        dp[0] = price[0]
        for i in range(1, n):
            dp[i] = price[i]
            for j in range(i):
                dp[i] = max(dp[i], dp[j] + price[i-j-1])
        
        return dp[n-1]
        
#{ 
 # Driver Code Starts
#Initial Template for Python 3

def main():

    T = int(input())

    while(T > 0):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        ob = Solution()
        print(ob.cutRod(a, n))

        T -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
