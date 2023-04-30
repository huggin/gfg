class Solution:
    def ExtractNumber(self, S):
        # code here
        ans = -1
        for s in S.split():
            if s.isdigit() and s.find("9") == -1:
                ans = max(ans, int(s))

        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input()
        ob = Solution()
        ans = ob.ExtractNumber(S)
        print(ans)
# } Driver Code Ends
