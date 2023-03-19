//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  string arrayGame(int N, int A[]) {
    // code here
    int ma = *max_element(A, A + N);
    int t = 0;
    for (int i = 0; i < N; ++i) {
      t += ma - A[i];
    }
    if (t == 0)
      return "Draw";
    return t % 2 ? "First" : "Second";
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, i;
    cin >> N;
    int A[N];
    for (i = 0; i < N; i++)
      cin >> A[i];
    Solution ob;
    cout << ob.arrayGame(N, A) << "\n";
  }
}
// } Driver Code Ends
