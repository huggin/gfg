# User function Template for python3
"""
class DLLNode:
    def __init__(self,val) -> None:
        self.data = val
        self.prev = None
        self.next = None
"""
import heapq


class Solution:
    def sortAKSortedDLL(self, head, k):
        # Code Here
        ans = None
        prev = None
        p = head
        pq = []
        while p:
            if len(pq) <= k:
                heapq.heappush(pq, p.data)
            else:
                break
            p = p.next

        while pq:
            nn = DLLNode(heapq.heappop(pq))
            if prev is None:
                ans = nn
                prev = nn
            else:
                prev.next = nn
                nn.prev = prev
                prev = nn
            if p:
                heapq.heappush(pq, p.data)
                p = p.next

        return ans


# {
# Driver Code Starts
import heapq


# A node of the doubly linked list
class DLLNode:

    def __init__(self, val):
        self.data = val
        self.next = None
        self.prev = None


# Function to insert a node at the end of the doubly linked list
def push(tail, new_data):
    new_node = DLLNode(new_data)
    new_node.next = None
    new_node.prev = tail

    if tail is not None:
        tail.next = new_node

    return new_node


# Function to print nodes in a given doubly linked list
def printList(head):
    while head is not None:
        print(head.data, end=" ")
        head = head.next
    print()


# Driver code
if __name__ == "__main__":
    t = int(input())  # Number of test cases
    for _ in range(t):
        arr = list(map(int, input().split()))  # Read the input array
        k = int(input())  # Read the value of k

        head = DLLNode(arr[0])
        tail = head

        for i in range(1, len(arr)):
            tail = push(tail, arr[i])

        solution = Solution()
        sorted_head = solution.sortAKSortedDLL(head, k)
        printList(sorted_head)
        print("~")

# } Driver Code Ends
