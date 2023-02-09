//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
    priority_queue<int> max_q;
    priority_queue<int, vector<int>, greater<int>> min_q;
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (min_q.size() == 0) {
            min_q.push(x);
        } else {
            if (x > min_q.top()) {
                min_q.push(x);
            } else {
                max_q.push(x);
            }
        }
        balanceHeaps();
    }
    //Function to balance heaps.
    void balanceHeaps()
    {
        if (min_q.size() - 2 == max_q.size()) {
            int temp = min_q.top();
            min_q.pop();
            max_q.push(temp);
        } else if (min_q.size() + 2 == max_q.size()) {
            int temp = max_q.top();
            max_q.pop();
            min_q.push(temp);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if (max_q.size() < min_q.size()) {
            return min_q.top();
        } else if (max_q.size() > min_q.size()) {
            return max_q.top();
        } else {
            return (min_q.top() + max_q.top()) * 0.5;
        }
    }
};


//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}
// } Driver Code Ends
