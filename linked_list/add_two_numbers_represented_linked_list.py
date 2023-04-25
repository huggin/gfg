# User function Template for python3

"""
class Node:
    def __init__(self,data):
        self.data=data
        self.next=None
        
class llist:
    def __init__(self):
        self.head=None
        self.tail=None
        
class carry_data:
    def __init__(self):
        self.data=0
"""


# Function which adds two linked lists of same size represented by head1
# and head2 and returns head of the resultant linked list. Carry
# is propagated while returning from the recursion
def addSameSize(h1, h2, carry):
    """
    param: h1,h2: head of linked list 1 and 2
    param: carry: is instance of carry_data class, used to store carry
    return: head of resultant linked list(same size), and set the carry data, so that it could be added further
    """
    # code here
    if h1.next == None and h2.next == None:
        d = h1.data + h2.data
        if d >= 10:
            d -= 10
            carry.data = 1
        else:
            carry.data = 0
        return Node(d)

    c = carry_data()
    temp = addSameSize(h1.next, h2.next, c)
    d = h1.data + h2.data + c.data
    if d >= 10:
        d -= 10
        carry.data = 1
    else:
        carry.data = 0
    ans = Node(d)
    ans.next = temp
    return ans


# This function is called after the smaller list is added to the sublist of
# bigger list of same size. Once the right sublist is added, the carry
# must be added to left side of larger list to get the final result.
def addCarryToRemaining(h1, curr, result, carry):
    """
    param: h1:      head of largest linked list
    param: curr:    node till largest linked list has been added
    param: result:  resultant linked list(not head),formed from above function
    param: carry:   is instance of carry_data class, used to store carry,

    return: None,   set new resultant head to result linklist.
    """

    # code here
    all = []
    while h1.next != curr:
        all.append(h1)
        h1 = h1.next
    all.append(h1)
    for i in range(len(all) - 1, -1, -1):
        all[i].data += carry.data
        if all[i].data == 10:
            all[i].data = 0
        else:
            carry.data = 0
            break

    h1.next = result.head
    result.head = all[0]


# {
# Driver Code Starts
# Initial Template for Python 3


# contributed by RavinderSinghPB
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class llist:
    def __init__(self):
        self.head = None
        self.tail = None


class carry_data:
    def __init__(self):
        self.data = 0


def append(h, t, data):
    if not h:
        h = Node(data)
        return (h, h)
    else:
        t.next = Node(data)
        return (h, t.next)


def push(head, data):
    nn = Node(data)
    nn.next = head
    return nn


def printlist(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()


def addList(head1, head2, size1, size2, result, carry):
    if not head1:
        result.head = head2
        return

    if not head2:
        result.head = head1
        return

    if size1 == size2:
        result.head = addSameSize(head1, head2, carry)
    else:
        diff = abs(size1 - size2)

        if size1 < size2:
            head1, head2 = head2, head1

        cur = head1
        for _ in range(diff):
            cur = cur.next

        result.head = addSameSize(cur, head2, carry)

        addCarryToRemaining(head1, cur, result, carry)

    if carry.data != 0:
        result.head = push(result.head, carry.data)


if __name__ == "__main__":
    t = int(input())
    for cases in range(t):
        size1, size2 = list(map(int, input().strip().split()))
        nodes1 = list(map(int, input().strip().split()))
        nodes2 = list(map(int, input().strip().split()))

        ll1 = llist()
        ll2 = llist()
        result = llist()
        carry = carry_data()

        for e in nodes1:
            ll1.head, ll1.tail = append(ll1.head, ll1.tail, e)

        for e in nodes2:
            ll2.head, ll2.tail = append(ll2.head, ll2.tail, e)

        addList(ll1.head, ll2.head, size1, size2, result, carry)

        printlist(result.head)
# } Driver Code Ends
