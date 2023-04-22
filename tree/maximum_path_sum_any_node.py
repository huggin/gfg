# User function Template for python3


'''
class Node:
    def __init__(self,val):
        self.data = val
        self.left = None
        self.right = None
'''
from collections import deque
import sys


class Solution:
    def find(self, node):
        if not node:
            return 0
        if not node.left and not node.right:
            self.ans = max(self.ans, node.data)
            return max(0, node.data)

        left = self.find(node.left)
        right = self.find(node.right)

        self.ans = max(self.ans, node.data + left + right)
        return max(0, node.data + left, node.data + right)

    # Function to return maximum path sum from any node in a tree.
    def findMaxSum(self, root):
        # Your code here
        self.ans = -sys.maxsize-1
        self.find(root)
        return self.ans

# {
 # Driver Code Starts
# Initial Template for Python 3


# Contributed by Suman Rana
sys.setrecursionlimit(100000)
# Tree Node


class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None


# Function to Build Tree
def buildTree(s):
    # Corner Case
    if (len(s) == 0 or s[0] == "N"):
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
    size = size+1

    # Starting from the second element
    i = 1
    while (size > 0 and i < len(ip)):
        # Get and remove the front of the queue
        currNode = q[0]
        q.popleft()
        size = size-1

        # Get the current node's value from the string
        currVal = ip[i]

        # If the left child is not null
        if (currVal != "N"):

            # Create the left child for the current node
            currNode.left = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.left)
            size = size+1
        # For the right child
        i = i+1
        if (i >= len(ip)):
            break
        currVal = ip[i]

        # If the right child is not null
        if (currVal != "N"):

            # Create the right child for the current node
            currNode.right = Node(int(currVal))

            # Push it to the queue
            q.append(currNode.right)
            size = size+1
        i = i+1
    return root


if __name__ == "__main__":
    t = int(input())
    for _ in range(0, t):
        root = buildTree(input())
        ob = Solution()
        print(ob.findMaxSum(root))


# } Driver Code Ends
