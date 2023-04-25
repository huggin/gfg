# User function Template for python3


class Solution:
    def pairAndSum(self, N, Arr):
        # code here
        c = [0] * 32
        for i in range(N):
            for j in range(32):
                if Arr[i] & (1 << j):
                    c[j] += 1

        ans = 0
        for i in range(32):
            ans += c[i] * (c[i] - 1) // 2 * (1 << i)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        Arr = list(map(int, input().strip().split(" ")))
        ob = Solution()
        print(ob.pairAndSum(N, Arr))
# } Driver Code Ends
