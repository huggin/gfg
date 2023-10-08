class Solution:
    # Your task is to complete this function
    # Function should return an integer denoting the required answer
    def findMaxDiff(self, arr, n):
        # Code here
        ls = [0] * n
        rs = [0] * n
        st = []
        for i in range(n):
            while len(st) > 0 and arr[i] <= arr[st[-1]]:
                st = st[:-1]
            if len(st) == 0:
                ls[i] = 0
            else:
                ls[i] = arr[st[-1]]
            st.append(i)

        st = []
        for i in range(n - 1, -1, -1):
            while len(st) > 0 and arr[i] <= arr[st[-1]]:
                st = st[:-1]
            if len(st) == 0:
                rs[i] = 0
            else:
                rs[i] = arr[st[-1]]
            st.append(i)

        return max(abs(ls[i] - rs[i]) for i in range(n))


# {
# Driver Code Starts
# Driver Program
if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.findMaxDiff(arr, n))
# Contributed By: Harshit Sidhwa
# } Driver Code Ends
