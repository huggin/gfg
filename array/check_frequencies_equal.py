# User function Template for python3
class Solution:
    def sameFreq(self, s):
        # code here
        cnt = [0] * 26
        for c in s:
            cnt[ord(c) - ord("a")] += 1

        cnt.sort()
        j = 0
        for i in range(26):
            if cnt[i] != 0:
                j = i
                break

        if cnt[j] == cnt[25]:
            return True
        if cnt[25] > cnt[j] + 1:
            return False

        cnt[25] -= 1
        if cnt[25] < cnt[24]:
            return False

        return True


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())

    for _ in range(T):
        s = input()
        ob = Solution()
        answer = ob.sameFreq(s)
        if answer:
            print(1)
        else:
            print(0)

# } Driver Code Ends
