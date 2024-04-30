# User function Template for python3

"""
# Node Class

class node:
    def __init__(self, val):
        self.data = val
        self.next = None

"""


class Solution:
    # Function to reverse a linked list.
    def arrangeCV(self, head):
        # Code here
        vowel = Node("@")
        consonant = Node("$")
        pv = vowel
        pc = consonant
        p = head
        while p != None:
            q = p.next
            if (
                p.data == "a"
                or p.data == "e"
                or p.data == "i"
                or p.data == "o"
                or p.data == "u"
            ):
                pv.next = p
                pv = p
            else:
                pc.next = p
                pc = p
            p = q

        pv.next = consonant.next
        pc.next = None
        return vowel.next


# {
# Driver Code Starts


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


if __name__ == "__main__":
    for i in range(int(input())):
        n = int(input())
        arr = [str(x) for x in input().split()]

        lis = Linked_List()
        for i in arr:
            lis.insert(i)

        newHead = Solution().arrangeCV(lis.head)
        printList(newHead)

# } Driver Code Ends
