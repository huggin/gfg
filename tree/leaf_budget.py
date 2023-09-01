# User function Template for python3

"""
class Node:
    def __init__(self,val):
        self.data=val
        self.left=None
        self.right=None
"""


class Solution:
    def getCount(self, root, n):
        # code here
        leaf = []

        def solve(p, level):
            if p is None:
                return
            if p.left is None and p.right is None:
                leaf.append(level)
            solve(p.left, level + 1)
            solve(p.right, level + 1)

        solve(root, 1)
        leaf.sort()
        ans = 0
        for a in leaf:
            if n >= a:
                ans += 1
                n -= a
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

from collections import deque


class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


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


def inord(root):
    if not root:
        return
    inord(root.left)
    print(root.data, end=" ")
    inord(root.right)


if __name__ == "__main__":
    test_cases = int(input())
    for cases in range(test_cases):
        s = input()
        k = int(input())
        root = buildTree(s)
        ob = Solution()
        res = ob.getCount(root, k)
        print(res)
# } Driver Code Ends
