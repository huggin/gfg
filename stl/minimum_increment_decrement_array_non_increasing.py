# User function Template for python3
import heapq


class Solution:
    def minOperations(self, a, n):
        # code here
        pq = []
        ans = 0
        for elem in a:
            if len(pq) > 0 and pq[0] < elem:
                ans += elem - pq[0]
                heapq.heapreplace(pq, elem)
            heapq.heappush(pq, elem)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = [int(x) for x in input().strip().split()]
        obj = Solution()
        print(obj.minOperations(a, n))


# } Driver Code Ends
