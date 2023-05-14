# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def postToInfix(self, postfix):
        # Code here
        stack = []
        for c in postfix:
            if c == "+" or c == "-" or c == "*" or c == "/":
                op2 = stack.pop()
                op1 = stack.pop()
                stack.append("(" + op1 + c + op2 + ")")
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
        res = ob.postToInfix(postfix)
        print(res)
# } Driver Code Ends
