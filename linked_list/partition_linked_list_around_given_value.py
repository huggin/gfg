# User function Template for python3

"""

class Node:
    def __init__(self, data):
		self.data = data
		self.next = None

"""


class Solution:
    def partition(self, head, x):
        # code here
        le = None
        eq = None
        gr = None
        prev_le = None
        prev_eq = None
        prev_gr = None
        while head:
            if head.data == x:
                if not eq:
                    eq = head
                else:
                    prev_eq.next = head
                prev_eq = head
            elif head.data < x:
                if not le:
                    le = head
                else:
                    prev_le.next = head
                prev_le = head
            else:
                if not gr:
                    gr = head
                else:
                    prev_gr.next = head
                prev_gr = head

            head = head.next

        if le != None:
            head = le
            if eq != None:
                prev_le.next = eq
                if gr != None:
                    prev_eq.next = gr
                    prev_gr.next = None
                else:
                    prev_eq.next = None
            else:
                if gr != None:
                    prev_le.next = gr
                    prev_gr.next = None
                else:
                    prev_le.next = None
        elif eq != None:
            head = eq
            if gr != None:
                prev_eq.next = gr
                prev_gr.next = None
            else:
                prev_eq.next = None
        else:
            head = gr
            if not head:
                prev_gr.next = None

        return head


# {
# Driver Code Starts
# Initial Template for Python 3


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        # self.tail

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            # arr.append(str(temp.data))
            temp = temp.next
        print()


if __name__ == "__main__":
    t = int(input())
    while t > 0:
        llist = LinkedList()
        n = input()
        values = list(map(int, input().split()))
        for i in reversed(values):
            llist.push(i)
        k = int(input())
        new_head = LinkedList()
        ob = Solution()
        new_head = ob.partition(llist.head, k)
        llist.head = new_head
        llist.printList()
        t -= 1


# } Driver Code Ends
