# User function Template for Python3


class Solution:
    def leftSmaller(self, n, a):
        # code here
        ans = list(-1 for _ in range(n))

        s = [a[0]]
        for i in range(1, n):
            while len(s) > 0 and s[-1] >= a[i]:
                s.pop()
            if len(s) == 0:
                ans[i] = -1
            else:
                ans[i] = s[-1]
            s.append(a[i])

        return ans


# {
# Driver Code Starts
# Initial Template for Python3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        a = input().split()
        for i in range(n):
            a[i] = int(a[i])

        ob = Solution()
        ans = ob.leftSmaller(n, a)
        for u in ans:
            print(u, end=" ")
        print()
# } Driver Code Ends
