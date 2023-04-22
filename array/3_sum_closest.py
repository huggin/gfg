# User function Template for python3

class Solution:
    def closest3Sum(self, A, N, X):
        # code here
        diff = int(1e5)
        ans = -1

        A.sort()
        for i in range(N):
            j, k = i+1, N-1
            while j < k:
                s = A[i] + A[j] + A[k]
                if s > X:
                    if diff >= s - X:
                        diff = s - X
                        ans = s
                    k -= 1
                else:
                    if diff >= X - s:
                        diff = X - s
                        ans = s
                    j += 1

        return ans


# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        N = int(input())
        Arr = input().split()
        for itr in range(N):
            Arr[itr] = int(Arr[itr])
        X = int(input())
        ob = Solution()
        print(ob.closest3Sum(Arr, N, X))
# } Driver Code Ends
