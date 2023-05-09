# User function Template for python3


class Solution:
    def findMaxLen(ob, S):
        # code here
        n = len(S)
        left = [0] * n
        right = [0] * n

        st = []
        for i in range(n):
            if S[i] == "(":
                st.append(i)
            else:
                if len(st) > 0:
                    left[i] = (
                        i - st[-1] + 1 + left[st[-1] - 1]
                        if st[-1] - 1 >= 0
                        else st[-1] + 1
                    )
                    st.pop()

        st = []
        for i in range(n - 1, -1, -1):
            if S[i] == ")":
                st.append(i)
            else:
                if len(st) > 0:
                    right[i] = (
                        st[-1] - i + 1 + right[st[-1] + 1]
                        if st[-1] + 1 < n
                        else st[-1] - i + 1
                    )
                    st.pop()

        ans = right[0]
        for i in range(1, n):
            ans = max(ans, left[i - 1] + right[i])

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S = input()

        ob = Solution()
        print(ob.findMaxLen(S))
# } Driver Code Ends
