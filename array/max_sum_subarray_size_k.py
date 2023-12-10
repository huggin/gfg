# User function Template for python3
class Solution:
    def maximumSumSubarray(self, K, Arr, N):
        # code here
        curr = 0
        for i in range(K):
            curr += Arr[i]

        ans = curr
        for i in range(K, N):
            curr = curr - Arr[i - K] + Arr[i]
            ans = max(ans, curr)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = input().split()
        N = int(N)
        K = int(K)
        Arr = list(map(int, input().strip().split(" ")))

        ob = Solution()
        print(ob.maximumSumSubarray(K, Arr, N))
# } Driver Code Ends
