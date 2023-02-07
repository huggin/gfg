//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

struct Node {
    int val;
    int index;
    Node *prev;
    Node *next;
    Node(int v, int key) : val(v), index(key), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    int cap;
    int size;
    unordered_map<int, Node*> m;
    Node *head;
    Node *last;
public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int c) : size(0), cap(c), head(new Node(0, 0)), last(nullptr)
    {
    }
    
    void insert(Node *p) {
        p->next = head->next;
        if (head->next) {
            head->next->prev = p;
        }
        p->prev = head;
        head->next = p;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if (m.find(key) == m.end()) {
            return -1;
        } 
        Node *p = m[key];
        if (p == last) {
            last = last->prev;
            last->next = nullptr;
            if (last == head) {
                last = p;
            }
        } else {
            p->next->prev = p->prev;
            p->prev->next = p->next;
        }
        insert(p);
        //if (p->val == 20) {
        //    cout << endl;
        //    cout << p->index << ' ' << key;
        //    cout << endl;
        //}
        
        return p->val;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here  
        Node *p = nullptr;
        if (m.find(key) == m.end()) {
            if (size == cap) {
                p = last;
                last = last->prev;
                last->next = nullptr;
                m.erase(p->index);
                p->val = value;
                p->index = key;
                if (last == head) last = p;
            } else {
                p = new Node(value, key);
                if (!last) {
                    last = p;
                }
                ++size;
            }
            m[key] = p;
        } else {
            p = m[key];
            p->index = key;
            p->val = value;
            if (p == last) {
                last = last->prev;
                last->next = nullptr;
                if (last == head) last = p;
            } else {
                p->prev->next = p->next;
                p->next->prev = p->prev;
            }
        }
        insert(p);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
