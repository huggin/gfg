# User function Template for python3


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def sort(self, h1):
        # return head
        if h1 is None or h1.next is None:
            return h1
        p = h1
        q = h1.next
        prev = None

        while q is not None:
            t = q.next
            q.next = prev
            prev = q
            p.next = t
            if t is None:
                p.next = prev
                break
            elif t.next is None:
                t.next = prev
                break
            p = t
            q = t.next

        return h1


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

        ob = Solution()
        resHead = ob.sort(ll1.head)
        printList(resHead)
        print()


# } Driver Code Ends
