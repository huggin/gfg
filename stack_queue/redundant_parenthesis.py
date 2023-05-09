# User function Template for python3


class Solution:
    def removeBrackets(self, s):
        # code here
        stack = []
        priority = []
        ops = []
        for c in s:
            if c == "(":
                ops.append(c)
            elif c == ")":
                op2 = stack.pop()
                pri = priority.pop()
                op = ops.pop()
                while op != "(":
                    if op == "+" or op == "-":
                        pri = min(pri, 1)
                    elif op == "*" or op == "/":
                        pri = min(pri, 2)
                    op1 = stack.pop()
                    pri = min(pri, priority.pop())
                    op2 = op1 + op + op2
                    op = ops.pop()
                if len(ops) > 0 and pri != 3:
                    # if ops[-1] == '/' or (ops[-1] == '*' or ops[-1] == '-':
                    if (
                        ops[-1] == "/"
                        or (ops[-1] == "*" or ops[-1] == "-")
                        and pri == 1
                    ):
                        op2 = "(" + op2 + ")"
                stack.append(op2)
                if op2[0] == "(":
                    priority.append(3)
                else:
                    priority.append(pri)
            elif c == "+" or c == "-":
                ops.append(c)
            elif c == "*" or c == "/":  # Bug in the test cases
                # elif c == '*':
                if priority[-1] == 1:
                    op2 = stack.pop()
                    if op2[0] != "(":
                        op2 = "(" + op2 + ")"
                    stack.append(op2)
                    priority[-1] = 3
                ops.append(c)
            # elif c == '/':
            #    op2 = stack.pop()
            #    priority.pop()
            #    if len(op2) > 1 and op2[0] != '(':
            #        op2 = '(' + op2 + ')'
            #    stack.append(op2)
            #    priority.append(3)
            #    ops.append(c)
            else:
                stack.append(c)
                priority.append(3)

        ans = stack[0]
        for i in range(len(ops)):
            ans += ops[i] + stack[i + 1]
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        Exp = input()

        ob = Solution()
        print(ob.removeBrackets(Exp))


# } Driver Code Ends
