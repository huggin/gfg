# User function Template for python3


class Solution:
    def reverseEqn(self, s):
        # code here
        num = 0
        stack = []
        for c in s:
            if c in ["+", "-", "*", "/"]:
                stack.append(str(num))
                num = 0
                stack.append(c)
            else:
                num = num * 10 + ord(c) - ord("0")
        stack.append(str(num))
        return "".join(reversed(stack))


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input().strip()
        ob = Solution()
        ans = ob.reverseEqn(s)
        print(ans)
# } Driver Code Ends
