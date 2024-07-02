# User function Template for python3


"""
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
"""


class Solution:
    def zigzag(self, head_node):
        # Complete this function
        p = head_node
        while p:
            q = p.next
            if q is None:
                break
            s = q.next
            if s is None:
                if p.data > q.data:
                    p.data, q.data = q.data, p.data
                break
            else:
                if p.data > q.data:
                    p.data, q.data = q.data, p.data
                if q.data < s.data:
                    q.data, s.data = s.data, q.data
            p = s
        return head_node


# {
# Driver Code Starts
# Initial Template for Python 3

import io
import sys


# Node class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Linked list class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # append at the end of the list
    def append(self, new_node):
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = self.tail.next


# Print linked list
def print_list(head_node):
    curr_node = head_node
    while curr_node is not None:
        print(curr_node.data, end=" ")
        curr_node = curr_node.next
    print()


if __name__ == "__main__":
    for cases in range(int(input())):
        n = int(input())
        nodes = list(map(int, input().strip().split()))

        a = LinkedList()
        for x in nodes:
            a.append(Node(x))

        print_list(Solution().zigzag(a.head))

# } Driver Code Ends
