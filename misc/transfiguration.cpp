//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int transfigure(string A, string B) {
    // Your code goes here
    int ca[256] = {0}, cb[256] = {0};
    for (auto c : A) {
      ca[c]++;
    }
    for (auto c : B) {
      cb[c]++;
    }
    for (int i = 0; i < 256; ++i) {
      if (ca[i] < cb[i])
        return -1;
    }
    int count = 0;
    for (int i = A.size() - 1, j = B.size() - 1; i >= 0 && j >= 0;) {
      if (A[i] == B[j]) {
        ++count;
        --i;
        --j;
      } else {
        --i;
      }
    }
    // cout << count << endl;
    return A.size() - count;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string A, B;
    cin >> A >> B;
    Solution obj;
    cout << obj.transfigure(A, B) << endl;
  }
}
// } Driver Code Ends
