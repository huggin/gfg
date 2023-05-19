# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def isIntervals(self, a, b):
        if a[0] > b[1] or a[1] < b[0]:
            return False
        return True

    def insertNewEvent(self, N, intervals, newEvent):
        # Code here
        if N == 0:
            return [newEvent]
        ans = []
        used = 0
        for c in intervals:
            if used == 0 and newEvent < c:
                used = 1
                while len(ans) > 0 and self.isIntervals(ans[-1], newEvent):
                    prev = ans.pop()
                    newEvent = [min(prev[0], newEvent[0]), max(prev[1], newEvent[1])]
                ans.append(newEvent)

            while len(ans) > 0 and self.isIntervals(ans[-1], c):
                prev = ans.pop()
                c = [min(prev[0], c[0]), max(prev[1], c[1])]
                if used == 0 and self.isIntervals(c, newEvent):
                    used = 1
                    c = [min(newEvent[0], c[0]), max(newEvent[1], c[1])]
            ans.append(c)

        if used == 0:
            while len(ans) > 0 and self.isIntervals(ans[-1], newEvent):
                prev = ans.pop()
                newEvent = [min(prev[0], newEvent[0]), max(prev[1], newEvent[1])]

            ans.append(newEvent)
        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        intervals = [list(map(int, input().split())) for i in range(N)]
        newEvent = list(map(int, input().split()))
        ob = Solution()
        res = ob.insertNewEvent(N, intervals, newEvent)
        print("[", end="")
        for i in range(len(res)):
            print("[", end="")
            print(str(res[i][0]) + "," + str(res[i][1]), end="")
            print("]", end="")
            if i < len(res) - 1:
                print(",", end="")
        print("]")
# } Driver Code Ende
