"""
# node class:

class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

"""


from collections import deque


class Solution:
    def solve(self, node, home):
        if not node:
            return 0

        if node.data == home:
            self.home_node = node
            return 1

        if node.left:
            self.parent[node.left] = node
        left = self.solve(node.left, home)
        if left == 1:
            return 1

        if node.right:
            self.parent[node.right] = node
        right = self.solve(node.right, home)
        if right == 1:
            return 1

        return 0

    def getAll(self, node, k):
        if k < 0 or not node:
            return 0

        return (
            node.data + self.getAll(node.left, k - 1) + self.getAll(node.right, k - 1)
        )

    def ladoos(self, root, home, k):
        # Your code goes here
        self.parent = {root: None}
        self.home_node = None
        self.solve(root, home)
        if not self.home_node:
            return 0
        ans = 0
        node = self.home_node
        ans += (
            node.data + self.getAll(node.left, k - 1) + self.getAll(node.right, k - 1)
        )

        while self.parent[node]:
            k -= 1
            if k >= 0:
                ans += self.parent[node].data
            if node == self.parent[node].left:
                ans += self.getAll(self.parent[node].right, k - 1)
            else:
                ans += self.getAll(self.parent[node].left, k - 1)
            node = self.parent[node]

        return ans


# {
# Driver Code Starts
# driver code:


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
    for _ in range(t):
        line = input()
        root = buildTree(line)
        line = input().strip().split()
        home = int(line[0])
        k = int(line[1])
        obj = Solution()
        print(obj.ladoos(root, home, k))


# } Driver Code Ends
