# User function Template for python3


class Solution:
    def findSubArraySum(self, Arr, N, k):
        # code here
        m = {}
        m[0] = 1
        prefix = 0
        ans = 0
        for a in Arr:
            prefix += a
            if prefix - k in m:
                ans += m[prefix - k]
            m[prefix] = m.get(prefix, 0) + 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        Arr = input().split()
        for itr in range(N):
            Arr[itr] = int(Arr[itr])
        k = int(input())
        ob = Solution()
        print(ob.findSubArraySum(Arr, N, k))
# } Driver Code Ends
