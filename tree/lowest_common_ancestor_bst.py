# User function Template for python3


# Function to find the lowest common ancestor in a BST.
def LCA(root, n1, n2):
    # code here.
    parent1 = []
    parent2 = []

    def solve(p, n, parent):
        if p is None:
            return 0
        if p.data == n:
            parent.append(p)
            return 1
        left = solve(p.left, n, parent)
        right = solve(p.right, n, parent)
        if left == 1 or right == 1:
            parent.append(p)
            return 1
        return 0

    solve(root, n1, parent1)
    solve(root, n2, parent2)
    s = set(parent1)
    for p in parent2:
        if p in s:
            return p
    return None


# {
# Driver Code Starts
# Initial Template for Python 3
from collections import deque


# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
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
    return root


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        s = input()
        root = buildTree(s)
        n1, n2 = list(map(int, input().split()))
        print(LCA(root, n1, n2).data)

# } Driver Code Ends
