//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
vector<Node*> bfs(Node *src){
    vector<Node*>ans;
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) {
        Node *u = q.front();
        ans.push_back(u);
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++){
            if (!visit[v[i]]){
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return ans;
}
bool checkedClone(Node* prev, Node* new1 ) {
    vector<Node*>prevAns = bfs(prev);
    vector<Node*>newAns = bfs(new1);
    for (int i = 0; i < prevAns.size(); i++) {
        // cout << prevAns[i] << " " << newAns[i] << endl;
        if (prevAns[i] == newAns[i]) {
            // cout << "hii";
            return false;
        }
    }
    return true;
}


// } Driver Code Ends
//User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
    unordered_map<Node*, Node*> m;
    unordered_map<Node*, int> v;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        Node* ans = new Node(node->val);
        m[node] = ans;
        queue<Node*> Q;
        Q.push(node);
        v[node] = 1;
        while(!Q.empty()) {
            auto current = Q.front();
            Q.pop();
            auto current2 = m[current];
            current2->val = current->val;
            for(auto w : current->neighbors) {
                //
                if (m.find(w) == m.end()) {
                    Node* p = new Node(w->val);
                    m[w] = p;
                    current2->neighbors.push_back(p);
                    if (!v[w]) {
                        v[w] = 1;
                        Q.push(w);
                    }
                } else {
                    current2->neighbors.push_back(m[w]);
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Node* root = NULL;
        vector<Node*>v(N);
        std::string buffer;
        std::getline(std::cin, buffer);
        for (int i = 0; i < N; i++)v[i] = new Node(i);
        for (int i = 0; i < N; i++) {
            std::vector<Node*> vec;
            std::string buffer;
            int data;
            std::getline(std::cin, buffer);
            std::istringstream iss(buffer);
            while (iss >> data)
                vec.push_back(v[data]);
            v[i]->neighbors = vec;
        }
        Solution ob;
        vector<Node*>prev = bfs(v[0]);
        Node* ans = ob.cloneGraph(v[0]);
        vector<Node*>now = bfs(ans);
        cout << checkedClone(v[0], ans) << endl;

    }
    return 0;
}
// } Driver Code Ends
