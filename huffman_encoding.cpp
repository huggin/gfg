//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct Node {
    int f;
    char c;
    Node *left;
    Node *right;
    
    Node(int freq, char ch): f(freq), c(ch), left(NULL), right(NULL) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->f > r->f);
    }
};

class Solution
{
    void preOrder(Node* p, vector<string>& ans, string s) {
        if (!p) return;
        preOrder(p->left, ans, s+'0');

        if (!p->left && !p->right) {
            ans.push_back(s);
            //cout << s <<' ' << p->c <<' ' << p->f<< endl;
        }
        preOrder(p->right, ans, s+'1');
    }
public:
	vector<string> huffmanCodes(string S,vector<int> f,int N)
	{
	    using Q = priority_queue<Node*, vector<Node*>, compare>;
	        
	    Q q;
	    for(int i = 0; i < N; ++i) {
	        q.emplace(new Node(f[i], S[i]));
	    }
	    Node *root = NULL;
	    while(!q.empty()) {
	        Node* c = q.top();
	        q.pop();
	        if (q.empty()) {
	            root = c;
	            break;
	        }
	        Node* c2 = q.top();
	        q.pop();
	        Node *p = new Node(c->f + c2->f, '\0');
	        p->left = c;
	        p->right = c2;
	        //q.emplace(p->f, count++, p);
	        q.emplace(p);
	    }
	    vector<string> ans;
	    preOrder(root, ans, "");
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends
