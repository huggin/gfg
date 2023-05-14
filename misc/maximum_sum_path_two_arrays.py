# User function Template for python3
class Solution:
    def maxPathSum(self, arr1, arr2, m, n):
        # code here
        sum1 = 0
        sum2 = 0
        ans = 0
        i, j = 0, 0
        while i < m or j < n:
            if i == m:
                sum2 += arr2[j]
                j += 1
            elif j == n:
                sum1 += arr1[i]
                i += 1
            elif arr1[i] < arr2[j]:
                sum1 += arr1[i]
                i += 1
            elif arr1[i] > arr2[j]:
                sum2 += arr2[j]
                j += 1
            else:
                ans += max(sum1, sum2) + arr1[i]
                i += 1
                j += 1
                sum1, sum2 = 0, 0

        return ans + max(sum1, sum2)


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        m, n = list(map(int, input().strip().split()))
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.maxPathSum(arr1, arr2, m, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
