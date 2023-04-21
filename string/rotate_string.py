# User function Template for python3

class Solution:
    def StringQuery(self, N, Q, S, Q1, Q2):
        # code here
        ans = []
        curr = 0
        for i in range(Q):
            if Q1[i] == 2:
                ans.append(S[(curr + Q2[i]) % N])
            else:
                curr = (curr + N - Q2[i]) % N

        return ans

# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N, Q = map(int, input().strip().split(' '))
        S = input()
        Q1 = []
        Q2 = []
        for i in range(Q):
            x, y = map(int, input().strip().split(' '))
            Q1.append(x)
            Q2.append(y)
        ob = Solution()
        ans = ob.StringQuery(N, Q, S, Q1, Q2)
        for i in ans:
            print(i)
# } Driver Code Ends
