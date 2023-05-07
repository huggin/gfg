# User function Template for python3


class Solution:
    def maxEvents(self, start, end, N):
        # code here

        events = list(zip(start, end))
        events.sort()
        s = {}

        for i in range(N - 1, -1, -1):
            if not events[i][1] in s:
                s[events[i][1]] = 1
            else:
                e = events[i][1]
                while e >= events[i][0]:
                    if not e in s:
                        s[e] = 1
                        break
                    e -= 1

        return len(s)


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        start = list(map(int, input().split()))
        end = list(map(int, input().split()))

        ob = Solution()
        print(ob.maxEvents(start, end, N))
# } Driver Code Ends
