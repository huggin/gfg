# User function Template for python3


def pthCommonAncestor(x, y, root, p, vec):
    # Your code here
    ans = -1
    while root:
        vec.append(root.data)
        if x <= root.data <= y:
            while len(vec) > 0 and p > 1:
                vec.pop()
                p -= 1
            if len(vec) > 0:
                ans = vec[-1]
            break
        elif x > root.data:
            root = root.right
        else:
            root = root.left

    return ans


# {
# Driver Code Starts

# Initial Template for Python 3

# Author - Sajal Agrawal
# sajal.agrawal1997@gmail.com


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def insert(num, root):
    if root is None:
        temp = Node(num)
        return temp
    elif root.data >= num:
        root.left = insert(num, root.left)
    else:
        root.right = insert(num, root.right)
    return root


for _ in range(int(input())):
    vec = []
    root = None

    n, p = map(int, input().split())
    for num in map(int, input().split()):
        root = insert(num, root)

    x, y = map(int, input().split())
    if x > y:
        x, y = y, x
    print(pthCommonAncestor(x, y, root, p, vec))

# } Driver Code Ends
