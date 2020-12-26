#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

const int maxN = 2e5 + 1;
const int maxD = 1e9 + 1;

set<int> s[2]; // s[0] - not largest power spells, s[1] - largest power spells
ll sum[2]; // sum[0] - sum spells power in set not largest, sum[1] - sum spells in set largest
int countDouble[2]; // countDouble[0] - how many lightning spells in not largest, countDouble[1] - how many lightning spells in largest
set<int> sDouble; // all the lightning spells

void updateSets(int id)
{
    int d = *s[id].rbegin();
    if(id == 1) d = *s[id].begin();
    bool present = sDouble.count(d);

    sum[id] -= d, sum[!id] += d;
    s[id].erase(d), s[!id].insert(d);
    countDouble[id] -= present, countDouble[!id] += present;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    scanf("%d", &n);
    
    
    while(n--)
    {
        int tp, d;
        scanf("%d %d", &tp, &d); // tp == 0 -> FIRE; tp == 1 -> LIGHTNING

        if(d > 0)
        {
            // at first insert in set not largest
            sum[0] += d;
            s[0].insert(d);
            countDouble[0] += tp;
            if(tp == 1) sDouble.insert(d);
        }
        else
        {
            d = -d;
            int id = 0;
            if(s[1].count(d)) id = 1;

            sum[id] -= d;
            s[id].erase(d);
            countDouble[id] -= tp;
            if(tp == 1) sDouble.erase(d);
        }
        
        int sumDouble = countDouble[0] + countDouble[1];

        while (s[1].size() < sumDouble) updateSets(0);
        while (s[1].size() > sumDouble) updateSets(1);
        // here the size of largest set is == total number of lightning spells

        // move spells from 1 set to the other unless the largest spells are in s[1]
        while (s[1].size() > 0 && s[0].size() > 0 && *s[0].rbegin() > *s[1].begin()) {
            updateSets(0);
            updateSets(1);
        }


        ll ans = sum[0] + sum[1] * 2;
        if (countDouble[1] == sumDouble && sumDouble > 0) { // if largest set contains all lighting spells && #lighting spells > 0
            ans -= *s[1].begin(); // can't double all the spells in largest set, so count just once the smallest
            if (s[0].size() > 0) ans += *s[0].rbegin(); // double the biggest in not largest set
        }
        cout << ans << endl;

    }


    
    return 0;
}
