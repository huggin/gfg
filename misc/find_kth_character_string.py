# User function Template for python3
class Solution:
    def kthCharacter(self, m, n, k):
        # code here
        k -= 1
        cnt = 1 << n
        i, r = k // cnt, k % cnt
        b = str(bin(m))[2:]
        c = 0 if b[i] == "0" else 1
        a = [c]
        a2 = []
        for _ in range(n):
            for e in a:
                if e == 1:
                    a2.append(1)
                    a2.append(0)
                else:
                    a2.append(0)
                    a2.append(1)
            a = a2
            a2 = []

        return a[r]


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        m, n, k = input().split()
        m, n, k = int(m), int(n), int(k)

        ob = Solution()
        answer = ob.kthCharacter(m, n, k)
        print(answer)

# } Driver Code Ends
