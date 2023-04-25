# User function Template for python3


class Solution:
    def constructList(self, Q, N):
        # code here
        ans = []
        curr = 0
        for i in range(N - 1, -1, -1):
            if Q[i][0] == 0:
                # print(curr)
                ans.append(Q[i][1] ^ curr)
            else:
                curr ^= Q[i][1]

        ans.append(curr)
        ans.sort()
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        Q = []

        for i in range(N):
            type, val = map(int, input().split())
            Q.append([type, val])

        ob = Solution()
        res = ob.constructList(Q, N)

        for i in res:
            print(i, end=" ")
        print()
# } Driver Code Ends
