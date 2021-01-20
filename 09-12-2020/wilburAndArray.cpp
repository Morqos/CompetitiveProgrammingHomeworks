#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 1e9 + 5;


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<int> seq(n);
    for(int &val: seq) scanf("%d", &val);

    ll ans = 0;
    ll nextNum = 0;
    for(int i = 0; i < n; i++)
    {
        if(nextNum != seq[i])
        {
            ans += abs(seq[i] - nextNum);
            nextNum += seq[i] - nextNum;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
