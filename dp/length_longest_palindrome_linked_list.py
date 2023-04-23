# your task is to complete this function
# function should return an integer
'''
class node:
    def __init__(self):
        self.data = None
        self.next = Non
'''


class Solution:
    def maxPalindrome(self, head):
        # Code here

        d = []
        p = head
        while p:
            d.append(p.data)
            p = p.next

        n = len(d)

        ans = 1
        dp = [[0 for i in range(n)] for j in range(n)]
        for i in range(n):
            dp[i][i] = 1

        for i in range(n-1):
            if d[i] == d[i+1]:
                dp[i][i+1] = 1
                ans = 2

        for k in range(2, n):
            for i in range(0, n-k):
                j = i + k
                if d[i] == d[j] and dp[i+1][j-1] == 1:
                    dp[i][j] = 1
                    ans = max(ans, j-i+1)

        return ans

        return ans

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

    def insert(self, data):
        if self.head == None:
            self.head = node()
            self.head.data = data
        else:
            new_node = node()
            new_node.data = data
            new_node.next = None
            temp = self.head
            while (temp.next):
                temp = temp.next
            temp.next = new_node


# Driver Program
if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        list1 = Linked_List()
        n = int(input())
        values = list(map(int, input().strip().split()))
        for i in values:
            list1.insert(i)
        obj = Solution()
        print(obj.maxPalindrome(list1.head))
# Contributed By: Harshit Sidhwa

# } Driver Code Ends
