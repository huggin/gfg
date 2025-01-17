from typing import List


class Solution:
    # Function to find the new string obtained by rolling out characters.
    def findRollOut(self, s: str, roll: list[int]) -> str:
        # Your code goes here
        n = len(s)
        cnt = [0] * (n + 1)
        for r in roll:
            cnt[0] += 1
            cnt[r] -= 1
        for i in range(1, n):
            cnt[i] += cnt[i - 1]

        return "".join(chr((ord(s[i]) - 97 + cnt[i]) % 26 + 97) for i in range(n))


# {
# Driver Code Starts
from typing import List


def main():
    t = int(input())
    for _ in range(t):
        s = str(input())
        roll = list(map(int, input().split()))
        solution = Solution()
        result = solution.findRollOut(s, roll)
        print(result)
        print("~")


if __name__ == "__main__":
    main()

# } Driver Code Ends
