class Solution:
    def shuffleArray(self, arr, n):
        # Your code goes here
        arr[:] = [item for pair in zip(arr[: n // 2], arr[n // 2 :]) for item in pair]


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        n = int(input())
        a = list(map(int, input().split()))
        ob = Solution()
        ob.shuffleArray(a, n)
        print(*a)
# } Driver Code Ends
