# User function Template for python3


import atexit
import sys
import io


class Solution:
    # Function to convert an infix expression to a postfix expression.
    def InfixtoPostfix(self, exp):
        # code here
        op = []
        ans = []
        ops = "+-*/^()"
        left = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3, '(': 0}
        right = {'+': 1, '-': 1, '*': 2, '/': 2, '^': 3, '(': 4}
        for c in exp:
            if not c in ops:
                ans.append(c)
            elif c == ')':
                while True:
                    if op[-1] == '(':
                        op.pop()
                        break
                    s2 = ans[-1]
                    ans.pop()
                    s1 = ans[-1]
                    ans.pop()
                    ans.append(s1+s2+op[-1])
                    op.pop()
                    if op[-1] == '(':
                        op.pop()
                        break
            elif c == '(':
                op.append(c)
            else:
                while len(op) > 0 and left[op[-1]] >= right[c]:
                    s2 = ans[-1]
                    ans.pop()
                    s1 = ans[-1]
                    ans.pop()
                    ans.append(s1+s2+op[-1])
                    op.pop()
                op.append(c)

        while len(op) > 0:
            s = op[-1]
            ans.append(s)
            op.pop()

        return ''.join(ans)

# {
 # Driver Code Starts
# Initial Template for Python 3


# This code is contributed by Nikhil Kumar Singh(nickzuck_007)

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        exp = str(input())
        ob = Solution()
        print(ob.InfixtoPostfix(exp))
# } Driver Code Ends
