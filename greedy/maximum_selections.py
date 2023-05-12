# ranges[i][0] is the start of ith range
# ranges[i][1] is the end of ith range


class Solution:
    def max_non_overlapping(self, ranges):
        # code here
        ranges.sort(key=lambda x: (x[1], x[0]))
        ans = 0
        prev = -1
        for r in ranges:
            if r[0] >= prev:
                ans += 1
                prev = r[1]

        return ans


# {
# Driver Code Starts
# driver code
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        line = input().strip().split()
        ranges = [[] for j in range(n)]
        j = 0
        for i in range(0, 2 * n, 2):
            ranges[j].append(int(line[i]))
            ranges[j].append(int(line[i + 1]))
            j += 1

        obj = Solution()
        print(obj.max_non_overlapping(ranges))
# } Driver Code Ends
