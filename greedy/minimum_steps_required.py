class Solution:
    def minSteps(self, str: str) -> int:
        # code here
        cnt = {"a": 0, "b": 0}
        prev = "c"
        for s in str:
            if s != prev:
                cnt[s] += 1
                prev = s

        return min(cnt["a"], cnt["b"]) + 1


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        str = input()

        obj = Solution()
        res = obj.minSteps(str)

        print(res)


# } Driver Code Ends
