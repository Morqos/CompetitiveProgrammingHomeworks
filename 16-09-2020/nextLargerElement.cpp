#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to store Next larger elements


vector <long long> nextLargerElement(long long arr[], int n){
    // Your code here
    
    deque<long long> deq;
    deq.push_back(arr[n-1]);

    vector<long long> ans(n);
    ans[n-1] = -1;

    for(int i = n - 2; i >= 0; i--)
    {
        while(!deq.empty() && deq.back() <= arr[i]) deq.pop_back();

        if(deq.empty()) ans[i] = -1;
        else ans[i] = deq.back();

        deq.push_back(arr[i]);
    }

    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        
        vector <long long> res = nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}
  // } Driver Code Ends
