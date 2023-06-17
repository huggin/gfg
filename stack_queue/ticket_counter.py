from collections import deque


class Solution:
    def distributeTicket(self, N: int, K: int) -> int:
        # Code Here
        q = deque()
        for i in range(1, N + 1):
            q.append(i)

        flag = True
        while len(q) > 1:
            for i in range(K):
                if flag:
                    q.popleft()
                else:
                    q.pop()
                if len(q) == 1:
                    return q.pop()
            flag = not flag
        return q.pop()


# {
# Driver Code Starts
t = int(input())
for _ in range(t):
    N, K = map(int, input().split())

    obj = Solution()
    res = obj.distributeTicket(N, K)

    print(res)
# } Driver Code Ends
