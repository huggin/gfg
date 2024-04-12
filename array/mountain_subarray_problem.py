# User function Template for python3


class Solution:
    def processqueries(self, arr, n, m, q):
        # code here
        dp1 = [0] * n
        dp2 = [0] * n
        for i in range(1, n):
            if arr[i] >= arr[i - 1]:
                dp1[i] = dp1[i - 1]
            else:
                dp1[i] = i

        for i in range(1, n):
            if arr[i] <= arr[i - 1]:
                dp2[i] = dp2[i - 1]
            else:
                dp2[i] = i

        ans = [None] * m
        for i in range(m):
            if dp1[dp2[q[i][1]]] <= q[i][0]:
                ans[i] = "Yes"
            else:
                ans[i] = "No"
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        n = int(input())
        arr = list(map(int, input().split()))
        m = int(input())
        q = list()
        for i in range(0, m):
            q.append(list(map(int, input().split())))
        # print(q)
        result = Solution().processqueries(arr, n, m, q)
        for i in result:
            print(i)

# } Driver Code Ends
