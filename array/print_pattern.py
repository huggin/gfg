# User function Template for python3


class Solution:
    def pattern(self, N):
        # code here
        ans = [N]
        if N <= 0:
            return ans
        p = N - 5
        flag = True
        while p != N:
            ans.append(p)

            if flag and p > 0:
                p -= 5
            else:
                flag = False
                p += 5

        ans.append(N)
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        ob = Solution()
        ans = ob.pattern(N)
        for i in ans:
            print(i, end=" ")
        print()
# } Driver Code Ends
