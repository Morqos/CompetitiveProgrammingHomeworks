// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



vector<int> leaders(int arr[], int n){
    int max = -1;
    vector<int> leaders;
    for(int i = n-1; i >= 0; i--)
    {
        if(arr[i] >= max) 
        {
            leaders.push_back(arr[i]);
            max = arr[i];
        }
    }
    reverse(leaders.begin(), leaders.end());
    
    return leaders;
}

// { Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        
        //calling leaders() function
        vector<int> v = leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends