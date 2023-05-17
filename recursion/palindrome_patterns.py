# User function Template for python3


class Solution:
    def solve(self, cnt, k, n, curr):
        if k == n // 2:
            self.ans.append("".join(curr))
            return

        for i in range(26):
            if cnt[i] >= 2:
                curr[k] = chr(ord("a") + i)
                curr[n - 1 - k] = curr[k]
                cnt[i] -= 2
                self.solve(cnt, k + 1, n, curr)
                cnt[i] += 2

    def all_palindromes(self, s):
        # Code here
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord("a")] += 1

        odd = 0
        c = " "
        for i in range(26):
            if cnt[i] % 2 == 1:
                odd += 1
                c = chr(ord("a") + i)

        if odd > 1:
            return []
        self.ans = []
        n = len(s)
        curr = [" "] * n

        if odd == 1:
            curr[n // 2] = c

        self.solve(cnt, 0, n, curr)
        return self.ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s = input()
        ob = Solution()
        ans = ob.all_palindromes(s)
        print("{", end=" ")
        for i in ans:
            print(i, end=" ")
        print("}")


# } Driver Code Ends
