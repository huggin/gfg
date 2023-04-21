# User function Template for python3


class Solution:
    def find(self, parent, i):
        while i != parent[i]:
            parent[i] = parent[parent[i]]
            i = parent[i]
        return i

    def merge(self, parent, i, j):
        i = self.find(parent, i)
        j = self.find(parent, j)
        if i == j:
            return

        if i < j:
            parent[j] = i
        else:
            parent[i] = j

    def mergeDetails(self, details):
        # code here
        n = len(details)
        parent = [1] * n
        for i in range(n):
            parent[i] = i

        for i in range(len(details)):
            for j in range(i+1, len(details)):
                for k in details[i][1:]:
                    if k in details[j][1:]:
                        self.merge(parent, i, j)
                        break

        ans = []
        m = {}
        for i in range(len(details)):
            if i == parent[i]:
                temp = [details[i][0]]
                for k in details[i][1:]:
                    if k not in temp:
                        temp.append(k)
                ans.append(temp)
                m[i] = len(ans) - 1
            else:
                j = self.find(parent, i)
                for k in details[i][1:]:
                    if not k in ans[m[j]]:
                        ans[m[j]].append(k)

        for i in range(len(ans)):
            half = sorted(ans[i][1:])
            ans[i][1:] = half

        return ans


# {
 # Driver Code Starts
# Initial Template for Python 3

if __name__ == "__main__":
    T = int(input())
    for t in range(T):

        n = int(input())
        details = []
        for i in range(n):
            detail = []
            name, m = map(str, input().strip().split())
            m = int(m)
            detail.append(name)
            l = list(map(str, input().strip().split()))
            detail.extend(l)
            details.append(detail)

        obj = Solution()
        ans = obj.mergeDetails(details)
        ans.sort()
        print('[', end='')
        for i in range(len(ans)):
            print('[', end='')
            for j in range(len(ans[i])):
                if j != len(ans[i]) - 1:
                    print(ans[i][j], end=', ')
                else:
                    print(ans[i][j], end='')
            if i != len(ans) - 1:
                print(end='], ')
            else:
                print(end=']')
        print(']')


# } Driver Code Ends
