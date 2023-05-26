class Solution:
    def find(self, arr, n):
        # Your code goes here
        ans = (arr[n - 1] + 1) // 2
        for i in range(n - 2, -1, -1):
            ans = (ans + arr[i] + 1) // 2
        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        ob = Solution()
        ans = ob.find(a, n)
        print(ans)
# } Driver Code Ends
