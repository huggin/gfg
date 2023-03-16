//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
 public:
  template <class T>
  static void input(vector<T> &A, int n) {
    for (int i = 0; i < n; i++) {
      scanf("%d ", &A[i]);
    }
  }

  template <class T>
  static void print(vector<T> &A) {
    for (int i = 0; i < A.size(); i++) {
      cout << A[i] << " ";
    }
    cout << endl;
  }
};

// } Driver Code Ends
class Solution {
 public:
  int getMinimumDays(int N, string S, vector<int> &P) {
    // code here
    int cnt = 0;
    for (int i = 1; i < N; ++i) {
      if (S[i] == S[i - 1]) ++cnt;
    }
    if (cnt == 0) return 0;
    for (int i = 0; i < N; ++i) {
      if (P[i] > 0 && S[P[i]] == S[P[i] - 1]) --cnt;
      if (P[i] < N - 1 && S[P[i]] == S[P[i] + 1]) --cnt;
      if (cnt <= 0) return i + 1;
      S[P[i]] = '?';
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d ", &t);
  while (t--) {
    int N;
    scanf("%d", &N);
    string S;
    cin >> S;

    vector<int> P(N);
    Array::input(P, N);

    Solution obj;
    int res = obj.getMinimumDays(N, S, P);

    cout << res << endl;
  }
}

// } Driver Code Ends
