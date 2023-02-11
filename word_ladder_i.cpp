//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  bool neighbor(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) return false;
    int ans = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) ++ans;
    }
    return ans == 1;
  }

 public:
  int wordLadderLength(string startWord, string targetWord,
                       vector<string>& wordList) {
    // Code here
    queue<string> Q;
    map<string, int> dist;
    dist[startWord] = 1;

    Q.push(startWord);

    while (!Q.empty()) {
      string c = Q.front();
      Q.pop();
      for (auto w : wordList) {
        if (dist.find(w) == dist.end() && neighbor(c, w)) {
          dist[w] = dist[c] + 1;
          Q.push(w);
        }
      }
    }
    if (dist.find(targetWord) == dist.end()) return 0;
    return dist[targetWord];
  }
};

//{ Driver Code Starts.
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<string> wordList(n);
    for (int i = 0; i < n; i++) cin >> wordList[i];
    string startWord, targetWord;
    cin >> startWord >> targetWord;
    Solution obj;
    int ans = obj.wordLadderLength(startWord, targetWord, wordList);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
