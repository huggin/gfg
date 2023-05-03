# User function Template for python3
from collections import defaultdict


class Solution:
    def mostBalloons(self, N, arr):
        # Code here
        if N == 1:
            return 1

        ans = 1
        for i in range(N):
            d = defaultdict(int)
            same = 1
            same_line = 0
            for j in range(N):
                if i == j:
                    continue
                if arr[i][0] == arr[j][0]:
                    if arr[i][1] == arr[j][1]:
                        same += 1
                        continue
                    else:
                        same_line += 1
                else:
                    d[(arr[i][1] - arr[j][1]) / (arr[i][0] - arr[j][0])] += 1

            max_d = max(d.values())

            ans = max(ans, same + same_line, same + max_d)
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

import math

if __name__ == "__main__":
    T = int(input())
    while T > 0:
        N = int(input())
        arr = [[] for j in range(N)]
        for j in range(2):
            inp = [int(i) for i in input().split()]
            for i in range(N):
                arr[i].append(inp[i])
        ob = Solution()
        print(ob.mostBalloons(N, arr))

        T -= 1
# } Driver Code Ends
