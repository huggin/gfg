//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
string isDivisibleBy5(string bin);

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    cout << isDivisibleBy5(s) << endl;
  }

  return 0;
}

// } Driver Code Ends

// User function Template for C++

string isDivisibleBy5(string bin) {
  // complete the function here
  int ans = 0;
  for (int i = 0; i < bin.size(); ++i) {
    ans = (ans * 2 + bin[i] - '0') % 5;
  }
  return ans == 0 ? "Yes" : "No";
}
