//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}


// } Driver Code Ends

struct TrieNode {
    TrieNode *children[26];
    bool leaf;
    TrieNode() : leaf(false) {
        memset(children, 0, sizeof(children));
    }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
    //Your code here
    TrieNode *root = new TrieNode();
    int ans = 0;
    for(int i = 0; i < s.size(); ++i) {
        TrieNode *p = root;
        for(int j = i; j < s.size(); ++j) {
            int c = s[j]-'a';
            if (!p->children[c]) {
                ++ans;
                p->children[c] = new TrieNode();
            }
            p = p->children[c];
        }
    }
    return ans + 1;
}
