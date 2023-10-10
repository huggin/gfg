# User function Template for python3
EPS = 1e-9


class Line:
    def __init__(self, p, q):
        self.a = p[1] - q[1]
        self.b = q[0] - p[0]
        self.c = -p[0] * self.a - p[1] * self.b
        self.norm()

    def norm(self):
        z = math.sqrt(self.a * self.a + self.b * self.b)
        self.a /= z
        self.b /= z
        self.c /= z

    def dist(self, p):
        return self.a * p[0] + self.b * p[1] + self.c


def det(a, b, c, d):
    return a * d - b * c


def betw(l, r, x):
    return min(l, r) <= x + EPS and x <= max(l, r) + EPS


def intersect_1d(a, b, c, d):
    if a > b:
        a, b = b, a
    if c > d:
        c, d = d, c
    return max(a, c) <= min(b, d) + EPS


class Solution:
    def doIntersect(self, p1, q1, p2, q2):
        # code here
        if not intersect_1d(p1[0], q1[0], p2[0], q2[0]) or not intersect_1d(
            p1[1], q1[1], p2[1], q2[1]
        ):
            return 0

        m = Line(p1, q1)
        n = Line(p2, q2)
        zn = det(m.a, m.b, n.a, n.b)

        if abs(zn) < EPS:
            if abs(m.dist(p2)) > EPS or abs(n.dist(p1)) > EPS:
                return 0
            return 1
        else:
            x = -det(m.c, m.b, n.c, n.b) / zn
            y = -det(m.a, m.c, n.a, n.c) / zn

            return int(
                betw(p1[0], q1[0], x)
                and betw(p1[1], q1[1], y)
                and betw(p2[0], q2[0], x)
                and betw(p2[1], q2[1], y)
            )


# {
# Driver Code Starts
# Initial Template for Python 3

import math

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        S1 = list(map(int, input().strip().split(" ")))
        S2 = list(map(int, input().strip().split(" ")))
        p1 = []
        q1 = []
        p2 = []
        q2 = []
        p1.append(S1[0])
        p1.append(S1[1])
        q1.append(S1[2])
        q1.append(S1[3])
        p2.append(S2[0])
        p2.append(S2[1])
        q2.append(S2[2])
        q2.append(S2[3])
        ob = Solution()
        ans = ob.doIntersect(p1, q1, p2, q2)
        print(ans)
# } Driver Code Ends
