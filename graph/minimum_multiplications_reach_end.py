# User function Template for python3

from typing import List
from collections import deque


class Solution:
    def minimumMultiplications(self, arr: List[int], start: int, end: int) -> int:
        # code here
        marked = [-1] * 100000
        marked[start] = 0

        q = deque()
        q.append(start)

        while len(q) > 0:
            c = q.popleft()
            if c == end:
                return marked[c]
            for a in arr:
                d = c * a % 100000
                if marked[d] == -1:
                    marked[d] = marked[c] + 1
                    q.append(d)

        return -1


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        start, end = list(map(int, input().split()))
        obj = Solution()
        print(obj.minimumMultiplications(arr, start, end))
# } Driver Code Ends
