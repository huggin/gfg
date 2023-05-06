# {
# Driver Code Starts
# Initial Template for Python 3

import heapq

# } Driver Code Ends
# User function Template for python3


class Solution:
    def Kclosest(self, arr, n, x, k):
        # Your code goes here
        heap = []
        for i in range(n):
            heapq.heappush(heap, (abs(arr[i] - x), arr[i]))

        ans = []
        while len(ans) < k:
            ans.append(heapq.heappop(heap)[1])

        ans.sort()
        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        line = input().strip().split()
        n = int(line[0])
        x = int(line[1])
        k = int(line[2])
        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        result = obj.Kclosest(arr, n, x, k)
        for i in result:
            print(i, end=" ")
        print()
# } Driver Code Ends
