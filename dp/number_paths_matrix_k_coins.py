#User function Template for python3
from functools import lru_cache


class Solution:
    def numberOfPath (self, n, k, arr):
        # code here
        @lru_cache(maxsize=None)
        def f(i, j, k):
            if i == 0 and j == 0 and k == arr[i][j]:
                return 1
            if i < 0 or j < 0 or k < 0:
                return 0
            
            return f(i-1, j, k-arr[i][j]) + f(i, j-1, k-arr[i][j])
            
        return f(n-1, n-1, k)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    ob = Solution()
    t = int (input ())
    for _ in range (t):
        k= int(input())
        n=int(input())
        l = list(map(int, input().split()))
        arr = list()
        c=0
        for i in range(0, n):
            temp = list()
            for j in range(0, n):
                temp.append(l[c])
                c += 1
            arr.append(temp)
        ans = ob.numberOfPath(n, k, arr);
        print(ans)


# } Driver Code Ends
