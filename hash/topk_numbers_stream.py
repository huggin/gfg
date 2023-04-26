# User function Template for python3


class Solution:
    def kTop(self, a, n, k):
        # code here.
        ans = []
        freq = {}
        pos = {}
        curr = []
        for item in a:
            if item not in pos:
                curr.append(item)
                freq[item] = 1
                pos[item] = len(curr) - 1
            else:
                freq[item] += 1

            for j in range(pos[item], 0, -1):
                if (
                    freq[curr[j - 1]] < freq[curr[j]]
                    or freq[curr[j - 1]] == freq[curr[j]]
                    and curr[j - 1] > curr[j]
                ):
                    curr[j - 1], curr[j] = curr[j], curr[j - 1]
                    pos[curr[j - 1]] = j - 1
                    pos[curr[j]] = j
                else:
                    break

            ans.extend(curr[:k])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


t = int(input())
for _ in range(0, t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    ob = Solution()
    ans = ob.kTop(a, n, k)
    print(*ans)


# } Driver Code Ends
