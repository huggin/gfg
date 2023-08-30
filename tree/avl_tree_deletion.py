# User function Template for python3

""" structure of tree node:

class Node:
    def __init__(self,x):
        self.data=x
        self.left=None
        self.right=None
        self.height=1

"""


def height(p):
    if p is None:
        return 0
    return p.height


def leftRotate(y):
    x = y.right
    t = x.left
    y.right = t
    x.left = y

    y.height = max(height(y.left), height(y.right)) + 1
    x.height = max(height(x.left), height(x.right)) + 1
    return x


def rightRotate(y):
    x = y.left
    t = x.right
    y.left = t
    x.right = y

    y.height = max(height(y.left), height(y.right)) + 1
    x.height = max(height(x.left), height(x.right)) + 1
    return x


def getBalance(p):
    if p is None:
        return 0
    return height(p.left) - height(p.right)


def minValueNode(p):
    while p.left:
        p = p.left
    return p


def deleteNode(root, key):
    # code here

    if root is None:
        return None
    if root.data < key:
        root.right = deleteNode(root.right, key)
    elif root.data > key:
        root.left = deleteNode(root.left, key)
    else:
        if root.left is None or root.right is None:
            temp = root.left if root.left is not None else root.right
            if temp is None:
                temp = root
                root = None
            else:
                root = temp
        else:
            p = minValueNode(root.right)
            root.data = p.data
            root.right = deleteNode(root.right, p.data)

    if root is None:
        return None

    root.height = max(height(root.left), height(root.right)) + 1
    balance = getBalance(root)

    if balance > 1:
        if getBalance(root.left) < 0:
            root.left = leftRotate(root.left)
        root = rightRotate(root)

    if balance < -1:
        if getBalance(root.right) > 0:
            root.right = rightRotate(root.right)
        root = leftRotate(root)

    return root


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import deque


class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None
        self.height = 1


def setHeights(n):
    if not n:
        return 0
    n.height = 1 + max(setHeights(n.left), setHeights(n.right))
    return n.height


def buildTree(s):
    # Corner Case
    if len(s) == 0 or s[0] == "N":
        return None

    # Creating list of strings from input
    # string after spliting by space
    ip = list(map(str, s.split()))

    # Create the root of the tree
    root = Node(int(ip[0]))
    size = 0
    q = deque()

    # Push the root to the queue
    q.append(root)
    size = size + 1

    # Starting from the second element
    i = 1
    while size > 0 and i < len(ip):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size - 1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if currVal != "N":
            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size + 1
        # For the right child
        i = i + 1
        if i >= len(ip):
            break
        currVal = ip[i]

        # If the right child is not null
        if currVal != "N":
            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size + 1
        i = i + 1

    setHeights(root)
    return root


def isBST(n, lower, upper):
    if not n:
        return True

    if n.data <= lower or n.data >= upper:
        return False

    return isBST(n.left, lower, n.data) and isBST(n.right, n.data, upper)


def isBalanced(n):
    if not n:
        return (0, True)

    lHeight, l = isBalanced(n.left)
    rHeight, r = isBalanced(n.right)

    if abs(lHeight - rHeight) > 1:
        return (0, False)

    return (1 + max(lHeight, rHeight), l and r)


def isBalancedBST(root):
    if not isBST(root, -1000000000, 1000000000):
        print("BST voilated, inorder traversal :", end=" ")

    elif not isBalanced(root)[1]:
        print("Unbalanced BST, inorder traversal :", end=" ")

    else:
        return True

    return False


def printInorder(n):
    if not n:
        return
    printInorder(n.left)
    print(n.data, end=" ")
    printInorder(n.right)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        s = input()
        root = buildTree(s)

        n = int(input())
        ip = [int(x) for x in input().split()]

        for i in range(n):
            root = deleteNode(root, ip[i])

            if not isBalancedBST(root):
                break

        if root is None:
            print("null")
        else:
            printInorder(root)
            print()

# } Driver Code Ends
