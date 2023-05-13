# User function Template for python3

""" structure of tree node:

class Node:
    def __init__(self,x):
        self.data=x
        self.left=None
        self.right=None
        self.height=1

"""


class Solution:
    def height(self, h):
        if h is None:
            return 0
        return h.height

    def getBalance(self, h):
        if not h:
            return 0
        return self.height(h.left) - self.height(h.right)

    def rotateLeft(self, h):
        x = h.right
        h.right = x.left
        x.left = h
        h.height = max(self.height(h.left), self.height(h.right)) + 1
        x.height = max(self.height(x.left), self.height(x.right)) + 1
        return x

    def rotateRight(self, h):
        x = h.left
        h.left = x.right
        x.right = h
        h.height = max(self.height(h.left), self.height(h.right)) + 1
        x.height = max(self.height(x.left), self.height(x.right)) + 1
        return x

    def insertToAVL(self, root, key):
        # add key to AVL (if it is not present already)
        # return root node
        if not root:
            return Node(key)

        if root.data < key:
            root.right = self.insertToAVL(root.right, key)
        elif root.data > key:
            root.left = self.insertToAVL(root.left, key)
        else:
            return root

        root.height = max(self.height(root.left), self.height(root.right)) + 1
        balance = self.getBalance(root)

        if balance > 1:
            if key > root.left.data:
                root.left = self.rotateLeft(root.left)
            return self.rotateRight(root)
        elif balance < -1:
            if key < root.right.data:
                root.right = self.rotateRight(root.right)
            return self.rotateLeft(root)

        return root


# {
# Driver Code Starts
# Initial Template for Python 3


class Node:
    def __init__(self, x):
        self.data = x
        self.left = None
        self.right = None
        self.height = 1


def isBST(n, lower, upper):
    if not n:
        return True

    if n.data <= lower or n.data >= upper:
        return False

    return isBST(n.left, lower, n.data) and isBST(n.right, n.data, upper)


def isBalanced(n):
    if not n:
        return (0, True)

    lHeight, left = isBalanced(n.left)
    rHeight, right = isBalanced(n.right)

    if abs(lHeight - rHeight) > 1:
        return (0, False)

    return (1 + max(lHeight, rHeight), left and right)


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
        n = int(input())
        ip = [int(x) for x in input().strip().split()]

        root = None

        for i in range(n):
            root = Solution().insertToAVL(root, ip[i])

            if not isBalancedBST(root):
                break

        printInorder(root)
        print()

# } Driver Code Ends
