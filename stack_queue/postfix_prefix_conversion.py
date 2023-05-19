# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def postToPre(self, post_exp):
        # Code here
        stack = []
        for c in post_exp:
            if c in ["+", "-", "*", "/"]:
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append(c + op1 + op2)
            else:
                stack.append(c)

        return stack[0]


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        postfix = input()
        ob = Solution()
        res = ob.postToPre(postfix)
        print(res)
# } Driver Code Ends
