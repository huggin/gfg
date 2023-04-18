# User function Template for python3


class Solution:
    def countTriplets(self, Arr, N, L, R):
        # code here
        Arr.sort()

        ans = 0
        for i in range(N):
            j = i + 1
            k = N - 1
            while j < k:
                if Arr[i] + Arr[j] + Arr[k] <= R:
                    ans += k - j
                    j += 1
                elif Arr[i] + Arr[j] + Arr[k] > R:
                    k -= 1

        ans2 = 0
        for i in range(N):
            j = i + 1
            k = N - 1
            while j < k:
                if Arr[i] + Arr[j] + Arr[k] <= L - 1:
                    ans2 += k - j
                    j += 1
                elif Arr[i] + Arr[j] + Arr[k] > L - 1:
                    k -= 1

        return ans - ans2


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        N = int(input())
        Arr = input().split()
        for itr in range(N):
            Arr[itr] = int(Arr[itr])
        L, R = input().split()
        L = int(L)
        R = int(R)
        ob = Solution()
        print(ob.countTriplets(Arr, N, L, R))
# } Driver Code Ends
