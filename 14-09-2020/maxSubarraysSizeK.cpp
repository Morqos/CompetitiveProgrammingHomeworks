#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


vector <int> max_of_subarrays(int *arr, int n, int k){
    // your code here
    deque<int> deq(k);
    
    vector<int> ans;
    
    for(int i = 0; i < k; i++) 
    {
        while ((!deq.empty()) && arr[i] >= arr[deq.back()]) deq.pop_back();
 
        deq.push_back(i);
    }
    
    for(int i = k; i < n; i++)
    {
        ans.push_back(arr[deq.front()]);
        
        while ((!deq.empty()) && i - (k - 1) > deq.front()) deq.pop_front();
        
        while ((!deq.empty()) && arr[i] >= arr[deq.back()]) deq.pop_back();
 
        deq.push_back(i);
    }
    
    ans.push_back(arr[deq.front()]);
    
    return ans;
    
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
