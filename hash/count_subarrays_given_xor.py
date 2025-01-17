from collections import defaultdict


class Solution:
    def subarrayXor(self, arr, k):
        # code here
        curr = 0
        freq = defaultdict(int)
        freq[0] = 1
        ans = 0

        for num in arr:
            curr ^= num

            t = curr ^ k
            ans += freq[t]

            freq[curr] += 1

        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    tc = int(input())

    for _ in range(tc):
        arr = list(map(int, input().split()))
        k = int(input())

        obj = Solution()
        print(obj.subarrayXor(arr, k))
        print("~")

# } Driver Code Ends
