# User function Template for python3


def manacher_odd(s):
    n = len(s)
    s = "$" + s + "^"
    p = [0] * (n + 2)
    l, r = 1, 1
    max_len = 0
    pos = -1
    for i in range(1, n + 1):
        p[i] = max(0, min(r - i, p[l + r - i]))
        while s[i - p[i]] == s[i + p[i]]:
            p[i] += 1
        if p[i] > max_len:
            max_len = p[i]
            pos = i
        if i + p[i] > r:
            r = i + p[i]
            l = i - p[i]

    return s[pos - p[pos] + 2 : pos + p[pos] - 1]


def LongestPalindromeSubString(text):
    # code here
    # return the longest palindrome substring
    s = "#" + "#".join(list(c for c in text)) + "#"
    ans = manacher_odd(s)

    return "".join(ans.split(sep="#"))


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        text = input().strip()
        print(LongestPalindromeSubString(text))

# } Driver Code Ends
