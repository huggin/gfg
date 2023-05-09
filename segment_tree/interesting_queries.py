# User function Template for python3
from collections import defaultdict
import math


class Solution:
    def solveQueries(self, nums, Queries, k):
        # Code here
        n = len(nums)
        nq = len(Queries)
        ans = [0] * nq
        block_size = int(math.sqrt(n)) + 1
        query = []

        for i in range(nq):
            query.append((Queries[i][0], Queries[i][1], i))

        query.sort(key=lambda x: (x[0] / block_size, x[1]))
        freq = defaultdict(int)

        cl, cr = 0, -1
        cnt = 0
        for q in query:
            l, r = q[0] - 1, q[1] - 1
            while cl > l:
                cl -= 1
                freq[nums[cl]] += 1
                if freq[nums[cl]] == k:
                    cnt += 1
            while cr < r:
                cr += 1
                freq[nums[cr]] += 1
                if freq[nums[cr]] == k:
                    cnt += 1
            while cl < l:
                freq[nums[cl]] -= 1
                if freq[nums[cl]] == k - 1:
                    cnt -= 1
                cl += 1
            while cr > r:
                freq[nums[cr]] -= 1
                if freq[nums[cr]] == k - 1:
                    cnt -= 1
                cr -= 1
            ans[q[2]] = cnt

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, q, k = input().split()
        n = int(n)
        q = int(q)
        k = int(k)
        nums = list(map(int, input().split()))
        Queries = []
        for _ in range(q):
            Queries.append(list(map(int, input().split())))
        obj = Solution()
        ans = obj.solveQueries(nums, Queries, k)
        for _ in ans:
            print(_)

# } Driver Code Ends
