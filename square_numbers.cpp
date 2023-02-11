//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  vector<int> prime;
  vector<int> m;
  long long ans = 0;
  long long n;
  void seive(int n) {
    vector<int> num(sqrt(n) + 1, 1);
    prime.reserve(4000);
    num[0] = num[1] = 0;
    for (int i = 2; i < num.size(); ++i) {
      if (num[i] == 1) {
        prime.push_back(i);
        for (int j = i + i; j < num.size(); j += i) {
          num[j] = 0;
        }
      }
    }
  }

  void dfs(int k, long long& c, int& current) {
    if (c * c > n) return;
    if (k == prime.size() || c * c * prime[k] * prime[k] > n) {
      int flag = (current % 2 == 0) ? -1 : 1;
      ans += flag * m[c];
      return;
    }
    c *= prime[k];
    current++;
    dfs(k + 1, c, current);
    c /= prime[k];
    current--;
    dfs(k + 1, c, current);
  }

 public:
  long long sqNum(long long N) {
    // code here
    n = N;
    m.assign(2, 0);
    for (int i = 2; i * i <= N; ++i) {
      m.push_back(N / (i * i));
    }
    seive(N);
    // cout << prime.size() << endl;
    // cout << m.size() << endl;
    long long c = 1;
    int num = 0;
    dfs(0, c, num);

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long N;

    cin >> N;

    Solution ob;
    cout << ob.sqNum(N) << endl;
  }
  return 0;
}
// } Driver Code Ends
