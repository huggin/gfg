# User function Template for python3
class Solution:
    def calc(self, s):
        n = len(s)
        lps = [0] * n
        for i in range(1, n):
            j = lps[i - 1]
            while j > 0 and s[j] != s[i]:
                j = lps[j - 1]

            if s[i] == s[j]:
                j += 1
            lps[i] = j

        return lps

    def isRepeat(self, s):
        # code here
        lps = self.calc(s)
        n = len(s)
        return 1 if lps[n - 1] != 0 and n % (n - lps[n - 1]) == 0 else 0


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.isRepeat(s)

        print(answer)


# } Driver Code Ends
