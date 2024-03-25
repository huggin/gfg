# User function Template for python3


class Solution:
    def lenOfLongestGP(self, arr, N):
        # code here
        arr.sort()
        ans = 1
        j = 0
        for i in range(N):
            if arr[i] == arr[j]:
                ans = max(ans, i - j + 1)
            else:
                j = i

        s = set(arr)
        for i in range(N):
            for j in range(i + 1, N):
                if arr[j] % arr[i] == 0 and arr[j] != arr[i]:
                    curr = 2
                    d = arr[j] // arr[i]

                    nv = arr[j] * d
                    while nv in s:
                        curr += 1
                        nv *= d

                    ans = max(ans, curr)

        return ans


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        arr = input().split()
        for itr in range(N):
            arr[itr] = int(arr[itr])

        ob = Solution()
        print(ob.lenOfLongestGP(arr, N))
# } Driver Code Ends
