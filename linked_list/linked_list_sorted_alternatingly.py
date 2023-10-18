# User function Template for python3

"""
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
"""


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def merge(p, q):
    ans = Node(0)
    prev = ans
    while p or q:
        if not p:
            prev.next = q
            q = q.next
        elif not q:
            prev.next = p
            p = p.next
        elif p.data < q.data:
            prev.next = p
            p = p.next
        else:
            prev.next = q
            q = q.next
        prev = prev.next

    prev.next = None

    return ans.next


def sort(head):
    # return head
    if not head or not head.next:
        return head

    a = []
    p = head
    while p:
        a.append(p)
        p = p.next
        a[-1].next = None

    while len(a) > 1:
        b = []
        n = len(a)
        for i in range(0, n, 2):
            if i + 1 < n:
                p = merge(a[i], a[i + 1])
                b.append(p)
            else:
                b.append(a[i])
        a = b.copy()

    return a[0]


# {
# Driver Code Starts
# Initial Template for Python 3


class Llist:
    def __init__(self):
        self.head = None

    def insert(self, data, tail):
        node = Node(data)

        if not self.head:
            self.head = node
            return node

        tail.next = node
        return node


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next


if __name__ == "__main__":
    t = int(input())

    for tcs in range(t):
        n1 = int(input())
        arr1 = [int(x) for x in input().split()]
        ll1 = Llist()
        tail = None
        for nodeData in arr1:
            tail = ll1.insert(nodeData, tail)

        resHead = sort(ll1.head)
        printList(resHead)
        print()


# } Driver Code Ends
