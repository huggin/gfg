from typing import List


class Solution:
    def maxMeetings(self, N: int, S: List[int], F: List[int]) -> List[int]:
        # code here
        meeting = []
        for i in range(N):
            meeting.append((S[i], F[i], i))

        meeting.sort(key=lambda a: (a[1], a[2]))

        ans = []
        ans.append(meeting[0][2] + 1)

        for i in range(1, N):
            if meeting[i][0] > F[ans[-1] - 1]:
                ans.append(meeting[i][2] + 1)

        return sorted(ans)


# {
# Driver Code Starts
class IntArray:
    def __init__(self) -> None:
        pass

    def Input(self, n):
        arr = [int(i) for i in input().strip().split()]  # array input
        return arr

    def Print(self, arr):
        for i in arr:
            print(i, end=" ")
        print()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())

        S = IntArray().Input(N)

        F = IntArray().Input(N)

        obj = Solution()
        res = obj.maxMeetings(N, S, F)

        IntArray().Print(res)


# } Driver Code Ends
