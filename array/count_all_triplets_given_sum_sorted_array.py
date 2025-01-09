import math


class Solution:
    def countTriplets(self, arr, target):
        # code here
        n = len(arr)
        ans = 0
        for i in range(n):
            j, k = i + 1, n - 1
            while j < k:
                if arr[i] + arr[j] + arr[k] > target:
                    k -= 1
                elif arr[i] + arr[j] + arr[k] < target:
                    j += 1
                else:
                    if arr[j] == arr[k]:
                        n = k - j + 1
                        ans += n * (n - 1) // 2
                        break
                    else:
                        jj = j
                        cnt = 0
                        while arr[j] == arr[jj]:
                            cnt += 1
                            jj += 1
                        cnt2 = 0
                        kk = k
                        while arr[k] == arr[kk]:
                            cnt2 += 1
                            kk -= 1
                        ans += cnt * cnt2
                        j = jj
                        k = kk

        return ans


# {
# Driver Code Starts
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        arr = list(map(int, input().split()))
        target = int(input())
        ob = Solution()
        ans = ob.countTriplets(arr, target)
        print(ans)
        print("~")
# } Driver Code Ends
