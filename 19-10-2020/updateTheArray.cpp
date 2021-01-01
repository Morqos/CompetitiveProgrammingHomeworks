#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 1e4 + 1;
const int maxD = 1e9 + 1;


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n, u;
        scanf("%d %d", &n, &u);

        vector<int> array(n, 0);

        while(u--)
        {
            int l, r, val;
            scanf("%d %d %d", &l, &r, &val);

            array[l] += val;
            array[r+1] -= val;
        }
        

        for(int i = 1; i < n; i++)
        {
            array[i] += array[i-1];
        }

        // FenwickTree/SegmentTree not needed because all the updating queries are before all the print queries
        

        int q;
        scanf("%d", &q);
        while(q--)
        {
            int index;
            scanf("%d", &index);

            printf("%d\n", array[index]);
        }
    }

    return 0;
}
