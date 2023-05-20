# User function Template for python3

"""
# Node Class

class node:
    def __init__(self, val):
        self.data = val
        self.next = None

"""


class Solution:
    def count(self, p):
        cnt = 0
        while p:
            cnt += 1
            p = p.next
        return cnt

    def reverse(self, p):
        prev = None
        while p:
            next = p.next
            p.next = prev
            prev = p
            p = next
        return prev

    def solve(self, p, q):
        while q:
            p.data, q.data = q.data - p.data, p.data
            p = p.next
            q = q.next

    # Function to reverse a linked list.
    def modifyTheList(self, head):
        # Code here
        n = self.count(head)
        k = (n + 1) // 2
        p = head
        prev = None
        while k > 0:
            prev = p
            p = p.next
            k -= 1

        p = self.reverse(p)
        self.solve(head, p)
        p = self.reverse(p)
        prev.next = p
        return head


# {
# Driver Code Starts
# Initial Template for Python 3


# Node Class
class Node:
    def __init__(self, val):
        self.data = val
        self.next = None


# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


def printList(head):
    tmp = head
    while tmp:
        print(tmp.data, end=" ")
        tmp = tmp.next
    print()


def reverseList(self, head):
    if head is None:
        return None

    prev = None
    current = head
    next = current.next

    while current is not None:
        next = current.next
        current.next = prev
        prev = current
        current = next

    return prev


if __name__ == "__main__":
    for i in range(int(input())):
        n = int(input())
        arr = [int(x) for x in input().split()]

        lis = Linked_List()
        for i in arr:
            lis.insert(i)
        # newHead = reverseList(newHead)
        newHead = Solution().modifyTheList(lis.head)
        printList(newHead)

# } Driver Code Ends
