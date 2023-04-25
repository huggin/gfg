# User function Template for python3
class Solution:
    def orGate(self, arr, N):
        # code here
        return 1 if 1 in arr else 0


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split(" ")
        for itr in range(N):
            arr[itr] = int(arr[itr])

        ob = Solution()
        print(ob.orGate(arr, N))
# } Driver Code Ends
