#User function Template for python3

'''
# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None
'''

class Solution:
    def reverseBetween(self, head, m, n):
        #code here
        newhead = head
        prev = None
        for i in range(m-1):
            prev = head
            head = head.next
            
        last = None
        for i in range(m, n+1):
            next = head.next
            head.next = last
            last = head
            head = next
        
        if prev:
            prev.next = last
        else:
            newhead = last
            
        while last.next:
            last = last.next
        last.next = head
        return newhead

#{ 
 # Driver Code Starts
#Initial Template for Python 3

#Initial Template for Python 3

import atexit
import io
import sys

_INPUT_LINES = sys.stdin.read().splitlines()
input = iter(_INPUT_LINES).__next__
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER

@atexit.register

def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())
    
# Node Class
class Node:
    def __init__(self, data):   # data -> value stored in node
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def append(self, new_value):
        new_node = Node(new_value)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
            return
        self.tail.next = new_node
        self.tail = new_node

    # prints the elements of linked list starting with head
    def printList(self, head):
        if head is None:
            print(' ')
            return
        curr_node = head
        while curr_node:
            print(curr_node.data,end=" ")
            curr_node=curr_node.next
        print()
    
if __name__ == '__main__':
    t=int(input())
    for cases in range(t):
        inp = list(map(int,input().split())) 
        N=inp[0]
        m=inp[1]
        n=inp[2]
        
        a = LinkedList() # create a new linked list 'a'.
        nodes = list(map(int, input().strip().split()))
        for x in nodes:
            a.append(x)
            
       
        ob=Solution()
        newhead=ob.reverseBetween(a.head, m, n)
        a.printList(newhead)
# } Driver Code Ends
