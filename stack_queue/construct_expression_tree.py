# User function Template for python3


def constructTree(postfix):
    # your code goes here
    s = []
    for c in postfix:
        if not isOperator(c):
            s.append(et(c))
        else:
            op2 = s.pop()
            op1 = s.pop()
            node = et(c)
            node.left = op1
            node.right = op2
            s.append(node)

    return s.pop()


# {
# Driver Code Starts
# Initial Template for Python 3


class et:
    def __init__(self, x):
        self.value = x
        self.left = None
        self.right = None


def isOperator(c):
    if c == "+" or c == "-" or c == "*" or c == "/" or c == "^":
        return True
    return False


def inorder(t):
    if t:
        inorder(t.left)
        print(t.value, end=" ")
        inorder(t.right)


for _ in range(int(input())):
    postfix = input()
    r = constructTree(postfix)
    inorder(r)
    print()

# } Driver Code Ends
