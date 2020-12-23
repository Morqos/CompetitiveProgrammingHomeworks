#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
 
const int MOD=1e9+7;
const int INF=1e9+7;

const int maxN = 500 + 1;

ll merge(vector<int> &arr,vector<int> &temp, int l,int m,int r)
{
    ll invCount = 0;

    int i = l, j = m, k = l;
    while(i <= m - 1 && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            invCount += (m-i);
        }
        k++;
    }

    while (i <= m - 1) { temp[k] = arr[i]; i++; k++; }

    while (j <= r) { temp[k] = arr[j]; j++; k++; }

    for (i = l; i <= r; i++) { arr[i] = temp[i]; }

    return invCount;
}

ll mergeSort(vector<int> &arr, vector<int> &temp, int l, int r)
{
    ll invCount = 0;
    if(l < r)
    {
        int m = (l + r) / 2;
        invCount += mergeSort(arr,temp, l,m);
        invCount += mergeSort(arr,temp, m+1,r);
        invCount += merge(arr,temp, l,m+1,r);
    }
    return invCount;
}

ll callMergeSort(vector<int> &arr, int n)
{
    vector<int> temp(n); 
    return mergeSort(arr,temp, 0,n - 1); 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n;
        scanf("%d", &n);

        vector<int> array(n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d", &array[i]);
        }

        ll ans = callMergeSort(array, n);

        // for(int v: array) cout<<v<<" ";
        // cout<<endl;

        cout<<ans<<endl;


    }


    
    return 0;
}
