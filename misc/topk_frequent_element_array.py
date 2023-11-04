from collections import Counter


class Solution:
    def topK(self, nums, k):
        # Code here
        c = Counter(nums)
        freq = []
        for a, v in c.most_common():
            freq.append((v, a))

        freq.sort(key=lambda x: (-x[0], -x[1]))
        return list(c[1] for c in freq)[0:k]


# {
# Driver Code Starts

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        a = list(map(int, input().strip().split()))
        n = a[0]
        nums = a[1:]
        k = int(input().strip())
        obj = Solution()
        ans = obj.topK(nums, k)
        for i in ans:
            print(i, end=" ")
        print()

# } Driver Code Ends
