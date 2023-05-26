//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct TrieNode {
  int freq;
  string s;
  TrieNode *children[27];
  TrieNode() : freq(0) { memset(children, 0, sizeof(children)); }
};

struct cmp {
  bool operator()(const pair<int, string> &l, const pair<int, string> &r) {
    if (l.first > r.first)
      return true;
    if (l.first == r.first && l.second < r.second)
      return true;
    return false;
  }
};

class AutoCompleteSystem {
  TrieNode *root;
  TrieNode *curr;
  string prev;

  int index(char c) {
    int d = c - 'a';
    if (c == ' ')
      d = 26;
    return d;
  }

  void put(TrieNode *p, const string &s, int freq) {
    for (char c : s) {
      int d = index(c);
      if (!p->children[d]) {
        p->children[d] = new TrieNode();
      }
      p = p->children[d];
    }
    p->freq = freq;
    p->s = s;
  }

  void get(TrieNode *p, string &prev, set<pair<int, string>, cmp> &sp) {
    if (!p)
      return;
    if (p->freq != 0) {
      sp.emplace(p->freq, prev);
    }
    for (int i = 0; i < 27; ++i) {
      if (i == 26)
        prev.push_back(' ');
      else
        prev.push_back('a' + i);
      get(p->children[i], prev, sp);
      prev.pop_back();
    }
  }

public:
  AutoCompleteSystem(vector<string> &sentences, vector<int> &times) {
    // write code for constructor
    root = new TrieNode();
    for (int i = 0; i < sentences.size(); ++i) {
      put(root, sentences[i], times[i]);
    }
    curr = root;
  }
  vector<string> input(char c) {
    // write code to return the top 3 suggestions when the current character in
    // the stream is c c == '#' means , the current query is complete and you
    // may save the entire query into historical data
    int d = index(c);
    prev.push_back(c);
    vector<string> ans;
    if (c == '#') {
      curr->freq++;
      curr = root;
      prev.clear();
      return ans;
    }
    if (!curr)
      return ans;
    if (!curr->children[d]) {
      curr->children[d] = new TrieNode();
      curr = curr->children[d];
      return ans;
    }

    set<pair<int, string>, cmp> sp;
    get(curr->children[d], prev, sp);

    int i = 0;
    for (auto it = sp.begin(); i < 3 && it != sp.end(); ++it, ++i) {
      ans.push_back(it->second);
    }
    curr = curr->children[d];
    return ans;
  }
};

/**
 * Your AutoCompleteSystem object will be instantiated and called as such:
 * AutoCompleteSystem* obj = new AutoCompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> sentences(n);
    vector<int> times(n);
    for (int i = 0; i < n; ++i) {
      getline(cin, sentences[i]);
      cin >> times[i];
      cin.ignore();
    }
    AutoCompleteSystem *obj = new AutoCompleteSystem(sentences, times);
    int q;
    cin >> q;
    cin.ignore();

    for (int i = 0; i < q; ++i) {
      string query;
      getline(cin, query);
      string qq = "";
      for (auto &x : query) {
        qq += x;
        vector<string> suggestions = obj->input(x);
        if (x == '#')
          continue;
        cout << "Typed : \"" << qq << "\" , Suggestions: \n";
        for (auto &y : suggestions) {
          cout << y << "\n";
        }
      }
    }
  }
  return 0;
}

// } Driver Code Ends
