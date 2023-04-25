# User function Template for python3


class Solution:
    def countSumSubsets(self, arr, N):
        # Code here
        ans = 0
        for i in range(1, 1 << N):
            total = 0
            for j in range(N):
                if i & (1 << j):
                    total += arr[j]

            if total % 2 == 0:
                ans += 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        obj = Solution()
        ans = obj.countSumSubsets(arr, n)
        print(ans)
# } Driver Code Ends
