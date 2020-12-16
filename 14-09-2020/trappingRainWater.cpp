#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;

const int MOD=1e9+7;
const int INF=1e9+5;

const int maxN=1e7+1;

 
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

        vector<int> seq(n);
        for(int &v: seq) scanf("%d", &v);

        vector<int> maxL(n);
        vector<int> maxR(n);

        maxL[0] = seq[0];
        for(int i = 1; i < n; i++)
        {
            maxL[i] = max(maxL[i-1], seq[i]);
        }

        maxR[n-1] = seq[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            maxR[i] = max(maxR[i+1], seq[i]);
        }

        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(min(maxL[i],maxR[i])-seq[i] > 0) ans += min(maxL[i], maxR[i]) - seq[i];
        }

        printf("%lld\n", ans);
    }

    return 0;
}
