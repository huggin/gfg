# User function Template for python3
from collections import deque

# Function to construct the BST from its given level order traversal.


def constructBst(arr, n):
    # Your code here
    if len(arr) == 0:
        return None

    root = Node(arr[0])
    q = deque()
    q.append((root, -(2**31), 2**31))
    i = 1
    while len(q) > 0 and i < n:
        curr = q.popleft()
        mi = curr[1]
        ma = curr[2]
        # print(curr[0].data, mi, ma, arr[i])
        if mi < arr[i] < curr[0].data:
            curr[0].left = Node(arr[i])
            q.append((curr[0].left, mi, curr[0].data))
            i += 1
        if i == n:
            break
        if curr[0].data < arr[i] < ma:
            curr[0].right = Node(arr[i])
            q.append((curr[0].right, curr[0].data, ma))
            i += 1

    return root


# {
# Driver Code Starts
# Initial Template for Python 3
class Node:
    def __init__(self, val):
        self.data = val
        self.left = None
        self.right = None


def preOrder(root):
    if root is None:
        return
    print(root.data, end=" ")
    preOrder(root.left)
    preOrder(root.right)


def main():
    testcases = int(input())
    while testcases > 0:
        root = None
        sizeOfArray = int(input())
        arr = [int(x) for x in input().strip().split()]

        root = constructBst(arr, sizeOfArray)

        preOrder(root)
        print()

        testcases -= 1


if __name__ == "__main__":
    main()
# } Driver Code Ends
