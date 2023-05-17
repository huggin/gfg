# User function Template for python3
# bad tests, can't pass all.


class Solution:
    def findSeq(self, n1, n2, n):
        # code here
        ans = []
        sieze = set()
        sieze.add(1)
        ans.append(1)
        for i in range(1, n):
            ans.append(ans[i - 1] + 1)
            for j in range(i - 1, -1, -1):
                d1 = n1 * ans[i - 1] - n2 * ans[j]
                d2 = n1 * ans[j] - n2 * ans[i - 1]
                if d1 >= ans[i]:
                    sieze.add(d1)
                if d2 >= ans[i]:
                    sieze.add(d2)
            while ans[i] in sieze:
                ans[i] += 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n1, n2, n = map(int, input().split())

        ob = Solution()
        ptr = ob.findSeq(n1, n2, n)

        for i in range(n):
            print(ptr[i], end=" ")
# } Driver Code Ends
