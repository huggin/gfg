# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3

"""
class Node:
    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None
"""
from math import inf
from sys import stdin, stdout
from collections import deque
from collections import defaultdict
import sys


class Solution:
    def solve(self, node, target):
        if not node:
            return (1, -sys.maxsize - 1, sys.maxsize, 0, 0)

        left = self.solve(node.left, target)
        right = self.solve(node.right, target)

        if left[0] == 1 and right[0] == 1 and left[1] < node.data < right[2]:
            total = left[3] + right[3] + node.data
            if total == target:
                self.ans = min(self.ans, left[4] + right[4] + 1)
            return (
                1,
                max(right[1], node.data),
                min(left[2], node.data),
                total,
                left[4] + right[4] + 1,
            )

        return (0, 0, 0, 0, 0)

    def minSubtreeSumBST(self, target, root):
        # code here
        self.ans = sys.maxsize
        self.solve(root, target)
        if self.ans == sys.maxsize:
            return -1
        return self.ans


# {
# Driver Code Starts.

# Initial Template for Python 3


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
    test_cases = int(input())
    for _ in range(test_cases):
        target = int(input())
        N = input()
        root = buildTree(N)
        res = Solution().minSubtreeSumBST(target, root)
        print(res)
# } Driver Code Ends
