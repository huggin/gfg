# User function Template for python3


class Solution:
    def countEvenSum(self, arr, n):
        # code here
        cnt = [0, 0]
        ans = 0
        for a in arr:
            if a % 2 == 0:
                ans += cnt[0] + 1
                cnt[0] += 1
            else:
                ans += cnt[1]
                cnt[0], cnt[1] = cnt[1], cnt[0] + 1
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countEvenSum(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
