# {
# Driver Code Starts
# Initial Template for Python 3

import math


# } Driver Code Ends
# User function Template for python3
class Solution:
    def findTriplets(self, arr):
        # Your code here
        if len(arr) == 0:
            return []
        a = list((v, k) for k, v in enumerate(arr))
        a.sort()
        n = len(arr)
        ans = []
        for i in range(n):
            j, k = i + 1, n - 1
            while j < k:
                if a[i][0] + a[j][0] + a[k][0] > 0:
                    k -= 1
                elif a[i][0] + a[j][0] + a[k][0] < 0:
                    j += 1
                else:
                    jj = j
                    aj = []
                    while jj < k and a[j][0] == a[jj][0]:
                        aj.append(jj)
                        jj += 1
                    for jj in aj:
                        ans.append(sorted([a[i][1], a[jj][1], a[k][1]]))

                    k -= 1
        return ans


# {
# Driver Code Starts.


def main():
    T = int(input())
    while T > 0:

        A = [int(x) for x in input().strip().split()]

        ob = Solution()
        res = ob.findTriplets(A)
        res = sorted(res)
        if len(res) == 0:
            print("[]")
        for i in range(len(res)):
            for j in range(len(res[i])):
                print(res[i][j], end=" ")
            print("")
        print("~")
        T -= 1


if __name__ == "__main__":
    main()

# } Driver Code Ends
