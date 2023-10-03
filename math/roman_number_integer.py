# User function Template for python3


class Solution:
    def romanToDecimal(self, S):
        # code here
        ans = 0
        i = 0
        n = len(S)
        while i < n:
            if S[i] == "M":
                ans += 1000
            elif S[i] == "D":
                ans += 500
            elif S[i] == "C":
                if i + 1 < n and (S[i + 1] == "D" or S[i + 1] == "M"):
                    ans -= 100
                else:
                    ans += 100
            elif S[i] == "L":
                ans += 50
            elif S[i] == "X":
                if i + 1 < n and (S[i + 1] == "L" or S[i + 1] == "C"):
                    ans -= 10
                else:
                    ans += 10
            elif S[i] == "V":
                ans += 5
            elif S[i] == "I":
                if i + 1 < n and (S[i + 1] == "V" or S[i + 1] == "X"):
                    ans -= 1
                else:
                    ans += 1
            i += 1

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        ob = Solution()
        S = input()
        print(ob.romanToDecimal(S))
# } Driver Code Ends
