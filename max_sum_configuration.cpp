//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int max_sum(int A[], int N);

int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }

    cout << max_sum(A, N) << endl;
    /*keeping track of the total sum of the array*/
  }
}

// } Driver Code Ends

/*You are required to complete this method*/
int max_sum(int A[], int N) {
  // Your code here
  int t = 0, ans = INT_MIN, now = 0;
  for (int i = 0; i < N; ++i) {
    t += A[i];
    now += i * A[i];
  }
  ans = max(now, ans);
  for (int i = 0; i < N; ++i) {
    now = (now - t) + A[i] * N;
    ans = max(now, ans);
  }
  return ans;
}
