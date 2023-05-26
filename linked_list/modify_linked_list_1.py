# User function Template for python3


class Solution:
    def modify_the_list(self, head):
        # code here
        stack = []
        p = head
        while p:
            stack.append(p.data)
            p = p.next

        n = len(stack)
        p = head
        k = n - 1
        while p:
            if k > (n - 1) // 2:
                p.data = stack[k] - p.data
            else:
                p.data = stack[k]
            p = p.next
            k -= 1
        return head


# {
# Driver Code Starts
# Initial Template for Python 3


class Node:
    def __init__(self, x):
        self.data = x
        self.next = None


def modify_the_list(head):
    current = head
    while current is not None:
        if current.next is not None and current.data == current.next.data:
            current.next = current.next.next
        else:
            current = current.next
    return head


def print_list(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.next
    print()


t = int(input())
while t > 0:
    n = int(input())
    linked_list_arr = list(map(int, input().split()))
    head = None
    temp = None
    for a in linked_list_arr:
        new_node = Node(a)
        if head is None:
            head = new_node
        else:
            temp.next = new_node
        temp = new_node
    head = Solution().modify_the_list(head)
    print_list(head)
    t -= 1
# } Driver Code Ends
