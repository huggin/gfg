#User function Template for python3

def count(a, b):
    ans = 0
    for i in range(18):
        if (a & (1 << i)) != (b & (1<<i)):
            ans += 1
    return ans

class Solution:
    def findX(self, arr, n, q):
        # code here
        ans = -1
        cnt = 0
        for i in range(len(arr)):
            k = count(arr[i], q)
            if ans == -1 or cnt > k or cnt == k and ans > arr[i]:
                ans = arr[i]
                cnt = k
        
        return ans

#{ 
 # Driver Code Starts
#Initial Template for Python 3





if __name__ == '__main__':
    tc = int(input())
    while tc > 0:
        n, q = list(map(int, input().strip().split()))
        arr = list(map(int, input().strip().split()))

        ans = Solution().findX(arr, n, q)
        print(ans)
        tc -= 1

# } Driver Code Ends
