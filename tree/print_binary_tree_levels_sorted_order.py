
class Solution:
    def binTreeSortedLevels(self, arr, n):
        # code here.
        ans = []
        m = 1
        level = []
        j = 0
        for i in range(n):
            if j < m:
                level.append(arr[i])
                j += 1
            else:
                level.sort()
                ans.append(level.copy())
                level.clear()
                m += m
                j = 1
                level.append(arr[i])

        level.sort()
        ans.append(level)

        return ans

# {
 # Driver Code Starts


t = int(input())
for tc in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    ob = Solution()
    res = ob.binTreeSortedLevels(arr, n)

    for i in range(len(res)):
        for j in range(len(res[i])):
            print(res[i][j], end=" ")
        print()

# Contributed By: Pranay Bansal
# } Driver Code Ends
