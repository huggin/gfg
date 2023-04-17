#User function Template for python3

'''
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

'''
#Function to sort the given doubly linked list using Merge Sort.

def length(p):
    ans = 0
    while p:
        p = p.next
        ans += 1
    return ans

def merge(left, right):
    head = Node(-1)
    prev = head
    while left or right:
        if not left:
            prev.next = right
            right.prev = prev
            break
        elif not right:
            prev.next = left
            left.prev = prev
            break
        elif left.data < right.data:
            prev.next = left
            left.prev = prev
            prev = left
            left = left.next
        else:
            prev.next = right
            right.prev = prev
            prev = right
            right = right.next
    
    if head.next:
        head.next.prev = None
        
    return head.next 

def sortDoubly(head):
    #Your code here
    if not head:
        return None
    if not head.next:
        return head
        
    n = length(head)
    
    half = n // 2
    p = head
    while half > 1:
        p = p.next
        half -= 1
    
    prev = p
    p = p.next
    prev.next = None
    if p:
        p.prev = None
    
    left = sortDoubly(head)
    right = sortDoubly(p)
    
    return merge(left, right)

#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys
sys.setrecursionlimit(1000000)
class Node:
	def __init__(self, data):
		self.data = data
		self.next = None
		self.prev = None

class DoublyLinkedList:
	def __init__(self):
		self.head = None
		self.tail = None

	def append(self, new_data):
		new_node = Node(new_data)
		if self.head is None:
			self.head = new_node
			self.tail = new_node
			return
		new_node.prev = self.tail
		self.tail.next = new_node
		self.tail = new_node
		
	def printList(self, node):
		while(node.next is not None):
			node = node.next
		while node.prev is not None:
		    node = node.prev
		while(node is not None):
		    print(node.data, end=" ")
		    node = node.next
		print()
		
		
		
		

        
def printList(node): 
        temp = node 
      
        while(node is not None): 
            print (node.data,end=" ")
            temp = node 
            node = node.next
        print()
        while(temp): 
            print (temp.data,end=" ") 
            temp = temp.prev 

		




if __name__=='__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        llist = DoublyLinkedList()
        for e in arr:
            llist.append(e)
        llist.head=sortDoubly(llist.head)
        printList(llist.head)
        print()


# } Driver Code Ends
