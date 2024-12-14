# your task is to complete this function
# function should return new head pointer
"""
class node:
    def __init__(self):
        self.data = None
        self.next = None
"""


class Solution:

    def deleteAllOccurances(self, head, x):
        fh = node()
        fh.next = head
        prev = fh
        p = head
        while p:
            if p.data == x:
                prev.next = p.next
                p = prev.next
            else:
                prev = p
                p = p.next
        return fh.next


# {
# Driver Code Starts
# Node Class
class node:
    def __init__(self):
        self.data = None
        self.next = None


# Linked List Class
class Linked_List:
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, data):
        if self.head == None:
            self.head = node()
            self.tail = self.head
            self.head.data = data
        else:
            new_node = node()
            new_node.data = data
            new_node.next = None
            self.tail.next = new_node
            self.tail = self.tail.next


def printlist(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print("")


def sizeofthelinkedlist(head):
    x = 0
    while head is not None:
        head = head.next
        x += 1
    return x


# Driver Program
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        list1 = Linked_List()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in values:
            list1.insert(i)
        x = int(input())
        ob = Solution()
        newhead = ob.deleteAllOccurances(list1.head, x)
        print(sizeofthelinkedlist(newhead))
        printlist(newhead)
        print("~")
# Contributed By: Harshit Sidhwa
# } Driver Code Ends
