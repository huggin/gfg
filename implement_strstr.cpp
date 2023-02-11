//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int strstr(string, string);

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    string b;

    cin >> a;
    cin >> b;

    cout << strstr(a, b) << endl;
  }
}

// } Driver Code Ends

// Function to locate the occurrence of the string x in the string s.
int strstr(string s, string x) {
  // Your code here
  for (int i = 0; i < s.size(); ++i) {
    int k = i;
    int j = 0;
    for (; j < x.size(); ++j) {
      if (s[k] == x[j]) {
        ++k;
      } else {
        j = 0;
        break;
      }
    }
    if (j == x.size()) return i;
  }
  return -1;
}
