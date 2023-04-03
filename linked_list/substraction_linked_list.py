#User function Template for python3
def getNumber(l):
    num = 0
    p = l
    while p:
        num = num * 10 + p.data
        p = p.next
    return num

def subLinkedList(l1, l2): 
    # Code here
    # return head of difference list
    a1 = getNumber(l1)
    a2 = getNumber(l2)
    
    a = abs(a1 - a2)
    arr = map(int, str(a))
    ans = LinkedList()
    for i in arr:
        ans.insert(i)
    return ans.head

#{ 
 # Driver Code Starts
#Initial Template for Python 3

# Node Class
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Linked List Class
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next

# prints the elements of linked list starting with head
def printList(n):
    while n:
        print(n.data,end=' ')
        n = n.next
    print()

if __name__ == '__main__':
    for _ in range(int(input())):
        
        n = int(input())
        arr1 = ( int(x) for x in input().split() )
        LL1 = LinkedList()
        for i in arr1:
            LL1.insert(i)
        
        m = int(input())
        arr2 = ( int(x) for x in input().split() )
        LL2 = LinkedList()
        for i in arr2:
            LL2.insert(i)
        
        res = subLinkedList(LL1.head, LL2.head)
        printList(res)
# } Driver Code Ends
