class Solution:
    def duplicates(self, arr, n):
        # code here
        ans = set()
        OFFSET = 100000
        for i in range(n):
            b = arr[i] if arr[i] >= 0 else arr[i] + OFFSET
            if arr[b] < 0:
                ans.add(b)
            else:
                arr[b] -= OFFSET

        if len(ans) == 0:
            return [-1]

        return sorted(ans)


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        res = Solution().duplicates(arr, n)
        for i in res:
            print(i, end=" ")
        print()


# } Driver Code Ends
