# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3
import heapq


class Solution:
    def maxCombinations(self, N, K, A, B):
        # Code here
        pq = []
        A.sort(reverse=True)
        B.sort(reverse=True)
        ans = []
        heapq.heappush(pq, (-A[0] - B[0], 0, 0))
        marked = set()
        while len(ans) < K:
            d, i, j = heapq.heappop(pq)
            ans.append(-d)
            if j + 1 < N and not i * N + j + 1 in marked:
                marked.add(i * N + j + 1)
                heapq.heappush(pq, (-A[i] - B[j + 1], i, j + 1))
            if i + 1 < N and not (i + 1) * N + j in marked:
                marked.add((i + 1) * N + j)
                heapq.heappush(pq, (-A[i + 1] - B[j], i + 1, j))

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = list(map(int, input().split()))
        A = list(map(int, input().split()))
        B = list(map(int, input().split()))
        ob = Solution()
        res = ob.maxCombinations(N, K, A, B)
        for val in res:
            print(val, end=" ")
        print()
# } Driver Code Ends
