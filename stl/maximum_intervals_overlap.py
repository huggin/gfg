# User function Template for python3
import heapq


class Solution:

    def findMaxGuests(self, Entry, Exit, N):
        # code here
        guests = [(Entry[i], Exit[i]) for i in range(N)]
        guests.sort()

        pq = []
        ans = 0
        time = -1
        for i in range(N):
            while len(pq) > 0 and pq[0] < guests[i][0]:
                heapq.heappop(pq)
            heapq.heappush(pq, guests[i][1])
            if ans < len(pq):
                ans = len(pq)
                time = guests[i][0]

        return (ans, time)

# {
 # Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':

    t = int(input())

    for _ in range(t):

        N = int(input())

        entry = [int(x) for x in input().split()]
        exit = [int(x) for x in input().split()]

        solObj = Solution()
        ans = solObj.findMaxGuests(entry, exit, N)
        print(ans[0], ans[1])


# } Driver Code Ends
