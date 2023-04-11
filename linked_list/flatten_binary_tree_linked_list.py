#User function Template for python3

class Solution:
    def solve(self, node, head, prev):
        if node == None:
            return head, prev
        
        right = node.right
        if head == None:
            head = node
            prev = head
        else:
            prev.right = node
            prev = node
        
        head, prev = self.solve(node.left, head, prev)
        node.left = None
        head, prev = self.solve(right, head, prev)
        
        return head, prev
    
    def flatten(self, root):
        #code here
        head = None
        prev = None
        head, prev = self.solve(root, head, prev)
        head.left = None
        prev.right = None
        
        return head

#{ 
 # Driver Code Starts
#Initial Template for Python 3

from collections import deque
# Tree Node
class Node:
    def __init__(self, val):
        self.right = None
        self.data = val
        self.left = None

    
# Function to Build Tree   
def buildTree(s):
    #Corner Case
    if(len(s)==0 or s[0]=="N"):
        return None
        
    # Creating list of strings from input 
    # string after spliting by space
    ip=list(map(str,s.split()))
    
    # Create the root of the tree
    root=Node(int(ip[0]))                     
    size=0
    q=deque()
    
    # Push the root to the queue
    q.append(root)                            
    size=size+1 
    
    # Starting from the second element
    i=1                                       
    while(size>0 and i<len(ip)):
        # Get and remove the front of the queue
        currNode=q[0]
        q.popleft()
        size=size-1
        
        # Get the current node's value from the string
        currVal=ip[i]
        
        # If the left child is not null
        if(currVal!="N"):
            
            # Create the left child for the current node
            currNode.left=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.left)
            size=size+1
        # For the right child
        i=i+1
        if(i>=len(ip)):
            break
        currVal=ip[i]
        
        # If the right child is not null
        if(currVal!="N"):
            
            # Create the right child for the current node
            currNode.right=Node(int(currVal))
            
            # Push it to the queue
            q.append(currNode.right)
            size=size+1
        i=i+1
    return root
    
def inorder(root):
    if root == None:
        return 
    
    inorder(root.left)
    print(root.data, end=" ")
    inorder(root.right)
    
    
if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases):
        s=input()
        root = buildTree(s)
        ob = Solution()
        ob.flatten(root)
        inorder(root)
                
        print()
            
# } Driver Code Ends
