# User function Template for python3
import heapq


class Solution:
    def maxDiamonds(self, A, N, K):
        # code here
        ans = 0
        pq = []
        for a in A:
            heapq.heappush(pq, -a)

        for _ in range(K):
            d = heapq.heappop(pq)
            ans += -d
            d = -(-d // 2)
            heapq.heappush(pq, d)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = map(int, input().split())
        A = list(map(int, input().split()))

        ob = Solution()
        print(ob.maxDiamonds(A, N, K))
# } Driver Code Ends
