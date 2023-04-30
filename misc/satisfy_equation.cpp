//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  vector<int> satisfyEqn(int A[], int N) {
    // code here
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        v.emplace_back(A[i] + A[j], i, j);
      }
    }
    sort(v.begin(), v.end());

    vector<int> ans{-1, -1, -1, -1};
    for (int i = 1; i < v.size(); ++i) {
      if (get<0>(v[i - 1]) == get<0>(v[i])) {
        for (int j = i; j < v.size(); ++j) {
          if (get<0>(v[j]) != get<0>(v[i - 1])) {
            i = j;
            break;
          }
          int a = get<1>(v[i - 1]);
          int b = get<2>(v[i - 1]);
          int c = get<1>(v[j]);
          int d = get<2>(v[j]);
          if (a == c || a == d || b == c || b == d)
            continue;
          vector<int> temp{a, b, c, d};
          if (ans[0] == -1 || ans > temp) {
            ans = temp;
          }
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;

    cin >> N;
    int A[N];

    for (int i = 0; i < N; i++)
      cin >> A[i];

    Solution ob;
    vector<int> ptr = ob.satisfyEqn(A, N);

    cout << ptr[0] << " " << ptr[1] << " " << ptr[2] << " " << ptr[3] << endl;
  }
  return 0;
}
// } Driver Code Ends
