#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
 
const int MOD=1e9+7;
const int INF=1e9+7;

const int maxN = 500 + 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    scanf("%d", &t);
    
    int nCase = 0;
    while((nCase++) < t)
    {
        int n;
        scanf("%d", &n);
        
        vector<int> hRungs(n+1);
        hRungs[0] = 0; // first entry representative of the ground, so h = 0
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &hRungs[i]);
        }

        // k is equal either to max (hRungs[i+1] - hRungs[i]) or max (hRungs[i+1] - hRungs[i]) + 1 for all i such that 0 <= i < n

        // calculate maxK
        int maxK = -1;
        for(int i = 0; i < n; i++)
        {
            if((hRungs[i+1] - hRungs[i]) > maxK) maxK = (hRungs[i+1] - hRungs[i]); 
        }

        // check if it works
        int store_maxK = maxK;
        bool isOk = true;
        for(int i = 0; i < n; i++)
        {
            if((hRungs[i+1] - hRungs[i]) < maxK) continue;

            if((hRungs[i+1] - hRungs[i]) == maxK) maxK--;
            else { isOk = false; break; }
        }

        if(!isOk) cout <<"Case "<<nCase<<": "<<(store_maxK+1);
        else cout <<"Case "<<nCase<<": "<<store_maxK;
        cout <<endl;
    }


    
    return 0;
}
