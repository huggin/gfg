//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  void multiple(long long res[3][3], long long f[3][3], int m) {
    long long temp[3][3] = {0};
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        for (int k = 0; k < 3; ++k) {
          temp[i][j] = (temp[i][j] + res[i][k] * f[k][j]) % m;
        }
      }
    }
    memcpy(res, temp, sizeof(temp));
  }

  void pow(long long f[3][3], int n, int m, long long res[3][3]) {
    while (n) {
      if (n & 1) {
        multiple(res, f, m);
      }
      long long temp[3][3];
      memcpy(temp, f, sizeof(temp));
      multiple(f, temp, m);
      n >>= 1;
    }
  }

public:
  long long genFibNum(long long a, long long b, long long c, long long n,
                      long long m) {
    // code here
    if (n <= 2)
      return 1 % m;
    long long f[3][3] = {0, 1, 0, b, a, 1, 0, 0, 1};
    long long res[3][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};

    pow(f, n - 2, m, res);
    return (res[1][0] + res[1][1] + res[1][2] * c) % m;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, n, m;

    cin >> a >> b >> c >> n >> m;

    Solution ob;
    cout << ob.genFibNum(a, b, c, n, m) << endl;
  }
  return 0;
}
// } Driver Code Ends
