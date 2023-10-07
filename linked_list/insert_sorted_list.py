# {
# Driver Code Starts
# Initial Template for Python 3


# Node Class
class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.prev = self.head

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.prev = self.head
        else:
            self.prev.next = new_node
            self.prev = self.prev.next


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()


# } Driver Code Ends
# User function Template for python3


class Solution:
    def sortedInsert(self, head1, key):
        # code here
        # return head of edited linked list
        p = head1
        ans = Node(key)
        prev = None
        while p is not None and p.data < key:
            prev = p
            p = p.next
        if prev is None:
            ans.next = head1
            return ans
        prev.next = ans
        ans.next = p
        return head1


# {
# Driver Code Starts.
if __name__ == "__main__":
    for _ in range(int(input())):
        n = int(input())

        a = LinkedList()
        nodes = list(map(int, input().strip().split()))
        for x in nodes:
            a.append(x)

        key = int(input())
        h = Solution().sortedInsert(a.head, key)
        printList(h)

# } Driver Code Ends
