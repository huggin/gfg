#User function Template for python3
class Solution:
    def search(self, A, i, j):
        ma = int(1e18)
        mi = 0
        
        lo = i
        hi = j
        diff = ma
        while lo <= hi:
            mid = lo + (hi - lo) // 2
            left = A[mid] - A[i]
            right = A[j+1] - A[mid]
            
            if left < right:
                if right - left < diff:
                    diff = right - left
                    ma = min(ma, right)
                    mi = max(mi, left)
                lo = mid + 1
            else:
                if left - right < diff:
                    diff = left - right
                    ma = min(ma, left)
                    mi = max(mi, right)
                hi = mid - 1
        
        return mi, ma
    
    def solve(self, A, k, n):
        left = self.search(A, 0, k)
        right = self.search(A, k+1, n-1)
        return max(right[1], left[1]) - min(right[0], left[0])
    
    def minDifference(self, N, A): 
        #code here
        sum = [0 for _ in range(N+1)]
        for i in range(0, N):
            sum[i+1] = sum[i] + A[i]
        
        ans = int(1e18)
        for i in range(1, N-2):
            ans = min(ans, self.solve(sum, i, N))
        return ans


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        N = int(input())
        A = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.minDifference(N, A)
        print(ans)


# } Driver Code Ends
