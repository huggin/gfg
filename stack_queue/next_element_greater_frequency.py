from collections import defaultdict


class Solution:
    def print_next_greater_freq(self, arr, n):
        # code here
        freq = defaultdict(int)
        for a in arr:
            freq[a] += 1

        st = []
        ans = [-1] * n
        for i in range(n - 1, -1, -1):
            while len(st) > 0 and freq[st[-1]] <= freq[arr[i]]:
                st.pop()
            if len(st) == 0:
                ans[i] = -1
            else:
                ans[i] = st[-1]
            st.append(arr[i])

        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = [int(x) for x in input().strip().split()]
        obj = Solution()
        ans = obj.print_next_greater_freq(arr, n)
        for i in ans:
            print(i, end=" ")
        print()


# } Driver Code Ends
