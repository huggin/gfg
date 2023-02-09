//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

struct TrieNode {
    TrieNode *children[26];
    bool leaf;
    TrieNode() : leaf(false) {
        memset(children, 0, sizeof(children));
    }
};

class Solution{
    bool search(TrieNode* root, const string& A, int d) {
        TrieNode* p = root;
        bool f = false;
        for(int i = d; i < A.size(); ++i) {
            int c = A[i] - 'a';
            if (!p->children[c]) {
                if (!p->leaf) return false;
                return search(root, A, i);
            } else {
                if (p->leaf) {
                    f = search(root, A, i);
                    if (f) return true;
                }
                p = p->children[c];
            }
        }
        return p->leaf;
    }
    
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        TrieNode* root = new TrieNode();
        for(const string& s : B) {
            TrieNode* p = root;
            for(int i = 0; i < s.size(); ++i) {
                int c = s[i]-'a';
                if (!p->children[c]) {
                    p->children[c] = new TrieNode();
                }
                p = p->children[c];
            }
            p->leaf = true;
        }
        return search(root, A, 0);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends
