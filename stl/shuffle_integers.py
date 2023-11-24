class Solution:
    def shuffleArray(self, arr, n):
        # Your code goes here
        j = 0
        mod = 100001
        for i in range(n):
            if i % 2 == 0:
                arr[i] += arr[j] * mod
            else:
                arr[i] += arr[n // 2 + j] * mod
                j += 1

        for i in range(n):
            arr[i] = (arr[i] // mod) % mod


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
