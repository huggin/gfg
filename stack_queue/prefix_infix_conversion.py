# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def preToInfix(self, pre_exp):
        # Code here
        stack = []
        for c in pre_exp:
            # print(stack)
            if c in ["+", "-", "*", "/"]:
                stack.append(c)
            else:
                curr = c
                while len(stack) > 0 and stack[-1] not in ["+", "-", "*", "/"]:
                    op1 = stack.pop()
                    op = stack.pop()
                    curr = "(" + op1 + op + curr + ")"
                stack.append(curr)

        return stack[0]


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        prefix = input()
        ob = Solution()
        res = ob.preToInfix(prefix)
        print(res)
# } Driver Code Ends
