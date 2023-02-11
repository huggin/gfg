//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
vector<string> extractIntegerWords(string s);

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    getline(cin, str);
    vector<string> ans = extractIntegerWords(str);
    if (ans.size() == 0)
      cout << "No Integers";
    else
      for (auto i : ans) cout << i << ' ';
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends

vector<string> extractIntegerWords(string s) {
  // code here
  int n = s.size();
  vector<string> ans;
  for (int i = 0; i < n;) {
    if (isdigit(s[i])) {
      int j = i;
      for (; isdigit(s[j]) && j < n; ++j)
        ;
      ans.push_back(s.substr(i, j - i));
      i = j;
    } else {
      ++i;
    }
  }
  return ans;
}
