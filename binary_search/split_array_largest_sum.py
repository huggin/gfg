# User function Template for python3


class Solution:
    def splitArray(self, arr, N, K):
        # code here
        def ok(v):
            curr = 0
            cnt = 0
            for a in arr:
                if curr + a > v:
                    cnt += 1
                    curr = a
                else:
                    curr += a
            if curr > 0:
                cnt += 1

            return cnt <= K

        lo, hi = max(arr), sum(arr)
        ans = hi
        while lo <= hi:
            mid = (lo + hi) // 2
            if ok(mid):
                ans = mid
                hi = mid - 1
            else:
                lo = mid + 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = map(int, input().split())
        arr = list(map(int, input().split()))

        ob = Solution()
        print(ob.splitArray(arr, N, K))
# } Driver Code Ends
