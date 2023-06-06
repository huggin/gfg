# User function Template for python3
class Solution:
    def leastPrimeFactor(self, n):
        # code here
        ans = [1] * (n + 1)
        for i in range(2, n + 1):
            if ans[i] == 1:
                ans[i] = i
                for j in range(i * i, n + 1, i):
                    if ans[j] == 1:
                        ans[j] = i
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3
if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n = int(input())
        ob = Solution()
        ans = ob.leastPrimeFactor(n)
        for i in range(1, n + 1):
            print(ans[i], end=" ")
        print()

# } Driver Code Ends
