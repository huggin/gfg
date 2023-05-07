# User function Template for python3

"""
# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
"""


class Solution:
    def insert(self, head, p):
        if not head or head.data >= p.data:
            p.next = head
            head = p
        else:
            q = head
            prev = None
            while q and q.data < p.data:
                prev = q
                q = q.next
            p.next = q
            prev.next = p

        return head

    def insertionSort(self, head):
        # code here
        ans = None
        while head:
            next = head.next
            ans = self.insert(ans, head)
            head = next
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


# Node Class
INF = float("inf")


class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


def printList(head):
    if head is None:
        print(" ")
        return
    curr_node = head
    while curr_node:
        print(curr_node.data, end=" ")
        curr_node = curr_node.next
    print(" ")


if __name__ == "__main__":
    t = int(input())
    for cases in range(t):
        n = int(input())
        a = Node(INF)
        nodes = list(map(int, input().strip().split()))
        ptr = a
        for x in nodes:
            ptr.next = Node(INF)
            ptr = ptr.next
            ptr.data = x
        a = a.next
        ob = Solution()
        head = ob.insertionSort(a)
        printList(head)
# } Driver Code Ends
