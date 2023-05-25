# {
# Driver Code Starts
# Initial Template for Python 3

# } Driver Code Ends
# User function Template for python3


class Solution:
    def minWindow(self, str1, str2):
        # Code here
        n = len(str1)
        m = len(str2)
        j, k = 0, 0
        i = 0
        ans = ""
        mi = n
        while j < n and k < m:
            if str1[j] == str2[k]:
                k += 1
            if k == m:
                i = j
                k = m - 1
                while i >= 0 and k >= 0:
                    if str1[i] == str2[k]:
                        k -= 1
                    i -= 1
                i += 1
                if mi > j - i + 1:
                    mi = j - i + 1
                    ans = str1[i : j + 1]
            j += 1
        return ans


# {
# Driver Code Starts.
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        str1 = input()
        str2 = input()
        ob = Solution()
        res = ob.minWindow(str1, str2)
        print(res)
# } Driver Code Ends
