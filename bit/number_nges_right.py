# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def count_NGEs(self, N, arr, queries, indices):
        # Code here
        ans = [0] * queries
        fenwick = [0] * 100002

        def add(i):
            i += 1
            while i < 100002:
                fenwick[i] += 1
                i += i & -i

        def get(i):
            i += 1
            ans = 0
            while i > 0:
                ans += fenwick[i]
                i -= i & -i
            return ans

        q = []
        for k, v in enumerate(indices):
            q.append((v, k))

        q.sort(reverse=True)
        # print(q)
        j = N - 1
        for k, v in q:
            while j > k:
                add(arr[j])
                j -= 1
            ans[v] = get(100000) - get(arr[k])
            # print(arr[j], ans[v])

        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = list(map(int, input().split()))
        queries = int(input())
        indices = list(map(int, input().split()))
        ob = Solution()
        NGEs = ob.count_NGEs(N, arr, queries, indices)
        for val in NGEs:
            print(val, end=" ")
        print()
# } Driver Code Ends
