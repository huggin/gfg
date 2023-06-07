# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
from typing import List
from itertools import permutations


class Solution:
    def kthPermutation(self, n: int, k: int) -> str:
        # code here
        ans = None
        for i in permutations(range(1, n + 1)):
            ans = i
            k -= 1
            if k == 0:
                break
        return "".join(str(c) for c in ans)


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, K = map(int, input().split())

        obj = Solution()
        res = obj.kthPermutation(N, K)

        print(res)


# } Driver Code Ends
