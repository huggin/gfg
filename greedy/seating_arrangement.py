from typing import List


class Solution:
    def is_possible_to_get_seats(self, n: int, m: int, seats: List[int]) -> bool:
        # code here
        ans = 0
        for i in range(m):
            if (
                (i - 1 < 0 or seats[i - 1] == 0)
                and (i + 1 >= m or seats[i + 1] == 0)
                and seats[i] == 0
            ):
                seats[i] = 1
                ans += 1

        return ans >= n 


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
        n = int(input())

        m = int(input())

        seats = IntArray().Input(m)

        obj = Solution()
        res = obj.is_possible_to_get_seats(n, m, seats)

        result_val = "Yes" if res else "No"
        print(result_val)

# } Driver Code Ends
