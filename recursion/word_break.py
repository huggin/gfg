# User function Template for python3


class Solution:
    def wordBreak(self, line, dictionary):
        # Complete this function
        n = len(line)

        def f(k):
            if k == n:
                return True

            ans = False
            for w in dictionary:
                if line[k : k + len(w)] == w:
                    ans |= f(k + len(w))

            return ans

        return f(0)


# {
# Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    test_case = int(input())

    for _ in range(test_case):
        number_of_elements = int(input())
        dictionary = [word for word in input().strip().split()]
        line = input().strip()
        ob = Solution()
        res = ob.wordBreak(line, dictionary)
        if res:
            print(1)
        else:
            print(0)
# } Driver Code Ends
