# User function Template for python3
from collections import deque


class Solution:
    def minMoves(self, arr):
        # code here
        n = len(arr)
        q = deque()
        for i in range(n):
            if arr[i]:
                q.append(i)

        if not q:
            return -1
        ans = 0
        while q:
            m = len(q)
            ans += 1
            for _ in range(m):
                j = q.popleft()
                if j > 0 and arr[j - 1] == 0:
                    arr[j - 1] = 1
                    q.append(j - 1)
                if j < n - 1 and arr[j + 1] == 0:
                    arr[j + 1] = 1
                    q.append(j + 1)

        return ans - 1


# {
# Driver Code Starts
def main():
    T = int(input())
    while T > 0:
        a = list(map(int, input().strip().split()))  # Convert input to list of integers
        print(Solution().minMoves(a))
        T -= 1
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
