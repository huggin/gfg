# User function Template for python3

"""
# Linked List Node 
class Node: 
	def __init__(self, d): 
		self.data = d 
		self.next = None
		"""


class Solution:
    def rearrangeEvenOdd(self, head):
        # code here
        odd = None
        even = None
        newodd = None
        neweven = None
        flag = True
        while head:
            next = head.next
            if flag:
                if odd == None:
                    odd = head
                    newodd = head
                else:
                    odd.next = head
                    odd = head
            else:
                if even == None:
                    even = head
                    neweven = head
                else:
                    even.next = head
                    even = head
            flag = not flag
            head = next

        if even:
            even.next = None
        odd.next = neweven
        return newodd


# {
# Driver Code Starts
# Python3 program to rearrange a linked list
# in such a way that all odd positioned
# node are stored before all even positioned nodes
# Linked List Node
class Node:
    def __init__(self, d):
        self.data = d
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # A utility function to create
    # a new node
    def newNode(self, key):
        temp = Node(key)
        self.next = None
        return temp

    # Rearranges given linked list
    # such that all even positioned
    # nodes are before odd positioned.
    # Returns new head of linked List.

    # A utility function to print a linked list
    def printlist(self, node):
        while node != None:
            print(node.data, end=" ")
            node = node.next

    # Function to insert a new node
    # at the beginning
    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node


# Driver code
if __name__ == "__main__":
    t = int(input())
    for cases in range(t):
        n = int(input())
        a = list(map(int, input().split()))
        ll = LinkedList()
        for i in range(n - 1, -1, -1):
            ll.push(a[i])
        Solution().rearrangeEvenOdd(ll.head)
        ll.printlist(ll.head)
        print()

# This code is contributed by Prerna Saini

# } Driver Code Ends
