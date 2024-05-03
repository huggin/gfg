# User function Template for python3


class Solution:
    def countPairs(self, arr, n):
        # code here
        j = 0
        s = set()
        ans = 0
        for i in range(n):
            while arr[i] in s:
                s.remove(arr[j])
                j += 1
            ans += len(s)
            s.add(arr[i])
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    tc = int(input())
    while tc > 0:
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        ans = ob.countPairs(arr, n)
        print(ans)
        tc -= 1

# } Driver Code Ends
