from collections import defaultdict


class Solution:
    def subCount(self, arr, n, k):
        # Your code goes here
        d = defaultdict(int)
        d[0] = 1
        tot = 0
        ans = 0
        for a in arr:
            tot += a
            tot %= k
            ans += d[tot]
            d[tot] += 1
        return ans


# {
# Driver Code Starts
if __name__ == "__main__":

    t = int(input())
    for _ in range(0, t):
        l = list(map(int, input().split()))
        n = l[0]
        k = l[1]
        a = list(map(int, input().split()))
        ob = Solution()
        print(ob.subCount(a, n, k))
# } Driver Code Ends
