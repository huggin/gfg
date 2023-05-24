# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def leastInterval(self, N, K, tasks):
        # Code here
        cnt = [0] * 26
        for t in tasks:
            cnt[ord(t) - 65] += 1

        ma, c = 0, 0
        for i in range(26):
            if cnt[i] > ma:
                ma = cnt[i]
                c = 1
            elif cnt[i] == ma:
                c += 1

        return max((ma - 1) * (K + 1) + 1 + c - 1, N)


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = list(map(int, input().split()))
        tasks = input().split()
        ob = Solution()
        res = ob.leastInterval(N, K, tasks)
        print(res)
# } Driver Code Ends
