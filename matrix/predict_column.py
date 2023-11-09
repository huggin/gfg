# User function Template for python3


class Solution:
    def columnWithMaxZeros(self, arr, N):
        # code here
        ans = -1
        ma = 0
        for i in range(N):
            cnt = sum(1 for j in range(N) if arr[j][i] == 0)
            if cnt > ma:
                ma = cnt
                ans = i
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = []
        for i in range(N):
            line = [int(x) for x in input().strip().split()]
            arr.append(line)
        ob = Solution()
        print(ob.columnWithMaxZeros(arr, N))


# } Driver Code Ends
