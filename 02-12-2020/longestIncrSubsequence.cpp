#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends


// return length of longest strictly increasing subsequence

int longestSubsequence(int n, int arr[])
{
   // your code here
   vector<int> seq;
   seq.push_back(arr[0]);
   
   for(int i = 1; i < n; i++)
   {
       if(seq.back() < arr[i]) seq.push_back(arr[i]);
       else
       {
           int index = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
           seq[index] = arr[i];
       }
   }
   
   return seq.size();
}
