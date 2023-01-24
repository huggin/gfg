//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

struct Node {
    Node *children[26];
    int size;
    
    Node(int sz = 0):size(sz) {
        memset(children, 0, sizeof(children));
    }
};

Node* put(Node* p, const string& s, int d) {
    if (!p) p = new Node(0);
    if (d == s.size()) {
        p->size++;
        return p;
    }
    char c = s[d]-'a';
    p->children[c] = put(p->children[c], s, d+1);
    p->size++;
    return p;
}

int get(Node *p, const string& s, int d) {
    if (!p) return 0;
    if (s.size() == d) return p->size;
    return get(p->children[s[d]-'a'], s, d+1);
}

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        // code here
        Node* root = new Node();
        for(int i = 0; i < N; ++i) {
            root = put(root, li[i], 0);
        }
        vector<int> ans;
        for(int i = 0; i < Q; ++i) {
            ans.push_back(get(root, query[i], 0));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends
