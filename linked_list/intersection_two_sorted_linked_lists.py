# User function Template for python3

""" structure of node:

class Node:
    def __init__(self,data):
        self.data=data
        self.next=None

"""


class Solution:
    def findIntersection(self, head1, head2):
        # return head
        ans = None
        prev = None
        while head1 and head2:
            if head1.data < head2.data:
                head1 = head1.next
            elif head1.data > head2.data:
                head2 = head2.next
            else:
                if prev is None:
                    ans = head1
                else:
                    prev.next = head1
                prev = head1

                head1 = head1.next
                head2 = head2.next

        if prev:
            prev.next = None
        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class linkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        if self.head is None:
            self.head = Node(data)
            self.tail = self.head
        else:
            self.tail.next = Node(data)
            self.tail = self.tail.next


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n1, n2 = [int(x) for x in input().split()]
        arr1 = [int(x) for x in input().split()]
        ll1 = linkedList()
        for i in arr1:
            ll1.insert(i)

        arr2 = [int(x) for x in input().split()]
        ll2 = linkedList()
        for i in arr2:
            ll2.insert(i)
        ob = Solution()
        result = ob.findIntersection(ll1.head, ll2.head)
        printList(result)
        print()

# } Driver Code Ends
