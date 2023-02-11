//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  vector<int> commonElements(int A[], int B[], int C[], int n1, int n2,
                             int n3) {
    // code here.
    int i = 0, j = 0, k = 0;
    n1 = unique(A, A + n1) - A;
    n2 = unique(B, B + n2) - B;
    n3 = unique(C, C + n3) - C;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3) {
      if (A[i] < B[j]) {
        ++i;
      } else if (A[i] > B[j]) {
        ++j;
      } else {
        if (C[k] < A[i]) {
          ++k;
        } else if (C[k] > A[i]) {
          ++i;
          ++j;
        } else {
          ans.push_back(C[k]);
          ++i;
          ++j;
          ++k;
        }
      }
    }
    if (ans.empty()) return vector<int>{-1};
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int A[n1];
    int B[n2];
    int C[n3];

    for (int i = 0; i < n1; i++) cin >> A[i];
    for (int i = 0; i < n2; i++) cin >> B[i];
    for (int i = 0; i < n3; i++) cin >> C[i];

    Solution ob;

    vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);
    if (res.size() == 0) cout << -1;
    for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
    cout << endl;
  }
}
// } Driver Code Ends
