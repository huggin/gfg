# User function Template for python3

class Node:

    def __init__(self, data=0):
        self.data = data
        self.left = None
        self.right = None


def construct(pre, s, e):
    if s > e:
        return None
    if s == e:
        return Node(pre[s])

    j = e+1
    for i in range(s+1, e+1):
        if pre[i] > pre[s]:
            j = i
            break

    node = Node(pre[s])
    node.left = construct(pre, s+1, j-1)
    node.right = construct(pre, j, e)
    return node

# Function that constructs BST from its preorder traversal.


def post_order(pre, size):
    # code here
    return construct(pre, 0, size-1)

# {
 # Driver Code Starts
# Initial Template for Python 3

# contributed by RavinderSinghPB


def postOrd(root):
    if not root:
        return
    postOrd(root.left)
    postOrd(root.right)
    print(root.data, end=' ')


if __name__ == '__main__':
    t = int(input())

    for _tcs in range(t):
        size = int(input())
        pre = [int(x)for x in input().split()]

        root = post_order(pre, size)

        postOrd(root)
        print()
# } Driver Code Ends
