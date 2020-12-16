#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find subarray with maximum sum
// arr: input array
// n: size of array
int maxSubarraySum(int arr[], int n){
    
    // Your code here
    bool allNegatives = true;
    int maxValue = int(-1e9);
    for(int i = 0; i < n; i++)
    {
        if(arr[i] > 0){ allNegatives=false; break; }
        maxValue = max(maxValue, arr[i]);
    }
    if(allNegatives) return maxValue;


    long long bestSum = (long long)(-1e9);
    long long currentSum = 0;
    for(int i = 0; i < n; i++)
    {
        currentSum = max((long long) 0, currentSum + (long long) arr[i]);
        bestSum = max(bestSum, currentSum);
    }

    return bestSum;

}

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
