from collections import deque


class Solution:
    def minStepToReachTarget(self, KnightPos, TargetPos, N):
        # Code here
        marked = [[0 for i in range(N)] for j in range(N)]
        marked[KnightPos[0] - 1][KnightPos[1] - 1] = 1
        q = deque()
        q.append(KnightPos[0] - 1)
        q.append(KnightPos[1] - 1)
        q.append(0)

        dx = [-2, -2, -1, -1, 1, 1, 2, 2]
        dy = [-1, 1, -2, 2, -2, 2, -1, 1]
        while len(q) > 0:
            x = q.popleft()
            y = q.popleft()
            dist = q.popleft()

            if x == TargetPos[0] - 1 and y == TargetPos[1] - 1:
                return dist

            for i in range(8):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx >= 0 and nx < N and ny >= 0 and ny < N and not marked[nx][ny]:
                    q.append(nx)
                    q.append(ny)
                    q.append(dist + 1)
                    marked[nx][ny] = 1

        return -1


# {
# Driver Code Starts
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N = int(input())
        KnightPos = list(map(int, input().split()))
        TargetPos = list(map(int, input().split()))
        obj = Solution()
        ans = obj.minStepToReachTarget(KnightPos, TargetPos, N)
        print(ans)

# } Driver Code Ends
