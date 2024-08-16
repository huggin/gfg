# User function Template for python3


class Solution:
    def inPlace(self, root):
        # Code Here
        n = 0
        p = root
        while p:
            n += 1
            p = p.next

        m = (n + 1) // 2 - 1
        p = root
        for _ in range(m):
            p = p.next
        q = p
        p = p.next
        q.next = None

        def reverse(p):
            prev = None
            while p:
                q = p.next
                p.next = prev
                prev = p
                p = q
            return prev

        def print2(p):
            while p:
                print(p.data)
                p = p.next

        q = reverse(p)

        p = root
        while q:
            np = p.next
            nq = q.next
            p.next = q
            q.next = np
            p = np
            q = nq

        return root


# {
# Driver Code Starts
# Initial Template for Python 3


class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


def printList(node):
    while node:
        print(node.data, end=" ")
        node = node.next
    print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().strip().split()))
        head = None
        if arr:
            head = Node(arr[0])
            tail = head
            for value in arr[1:]:
                tail.next = Node(value)
                tail = tail.next

        ob = Solution()
        ans = ob.inPlace(head)
        printList(ans)

# } Driver Code Ends
