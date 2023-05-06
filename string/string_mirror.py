class Solution:
    def stringMirror(self, str: str) -> str:
        # code here
        ans = []
        ans.append(str[0])
        n = len(str)
        for i in range(1, n):
            if str[i] <= str[i - 1]:
                ans.append(str[i])
            else:
                break

        if len(ans) >= 2 and ans[0] == ans[1]:
            return ans[0] * 2
        ans.extend(ans[::-1])
        return "".join(ans)


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        str = input()

        obj = Solution()
        res = obj.stringMirror(str)

        print(res)


# } Driver Code Ends
