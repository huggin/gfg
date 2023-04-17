# User function Template for python3
import heapq


class Solution:
    def kthLargest(self, k, arr, n):
        # code here
        ans = []
        heap = []
        for i in range(n):
            if len(heap) < k - 1:
                ans.append(-1)
                heapq.heappush(heap, arr[i])
            elif len(heap) == k - 1:
                heapq.heappush(heap, arr[i])
                ans.append(heap[0])
            else:
                if arr[i] <= heap[0]:
                    ans.append(heap[0])
                else:
                    heapq.heapreplace(heap, arr[i])
                    ans.append(heap[0])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k, n = map(int, input().split())
        arr = list(map(int, input().split()))

        ob = Solution()
        print(*ob.kthLargest(k, arr, n))
# } Driver Code Ends
