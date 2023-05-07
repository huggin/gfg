# User function Template for python3
# Given below is the structure of Node class
# list moves from left to right
# class node:
#     def __init__(self):
#         self.data = None
#         self.left = None
#         self.right = None


class Solution:
    def mailDesign(self, N, Q, query):
        # code here
        marked = [0] * (N + 1)
        access = [0] * (N + 1)
        time = 1
        for i in range(Q):
            curr = query[2 * i + 1]
            access[curr] = time
            time += 1
            ops = query[2 * i]
            if ops == 1:
                marked[curr] = 1
            elif ops == 2:
                marked[curr] = 2
            elif ops == 3:
                marked[curr] = 2
            elif ops == 4:
                marked[curr] = 1

        sort = [[], [], []]
        for i in range(1, N + 1):
            sort[marked[i]].append((access[i], i))

        prev = [None, None, None]
        ans = [None, None, None]
        for i in range(3):
            sort[i].sort()
            for a in sort[i]:
                curr = node()
                curr.data = a[1]
                if not ans[i]:
                    ans[i] = curr
                else:
                    prev.right = curr
                    curr.left = prev
                prev = curr
            if not ans[i]:
                ans[i] = node()
                ans[i].data = "EMPTY"

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


class node:
    def __init__(self):
        self.data = None
        self.left = None
        self.right = None


def printlist(head):
    temp = head
    while temp is not None:
        print(temp.data, end=" ")
        temp = temp.right
    print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N, Q = [int(x) for x in input().split()]
        query = input().split()
        for i in range(2 * Q):
            query[i] = int(query[i])

        ob = Solution()
        ans = ob.mailDesign(N, Q, query)
        for i in range(3):
            printlist(ans[i])
# } Driver Code Ends
