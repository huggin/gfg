# User function Template for python3


class Solution:
    def solve(self, k, nums, curr):
        if k == len(nums):
            self.ans.add(tuple(curr))
            return

        self.solve(k + 1, nums, curr)
        curr.append(nums[k])
        self.solve(k + 1, nums, curr)
        curr.pop()

    def printUniqueSubset(self, nums):
        # Code here
        nums.sort()
        self.ans = set()
        curr = []
        self.solve(0, nums, curr)
        return sorted(list(self.ans))


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        nums = list(map(int, input().split()))
        ob = Solution()
        res = ob.printUniqueSubset(nums)
        print("[ ", end="")
        for subset in res:
            print("[ ", end="")
            for val in subset:
                print(val, end=" ")
            print("]", end="")
        print(" ]")
# } Driver Code Ends
