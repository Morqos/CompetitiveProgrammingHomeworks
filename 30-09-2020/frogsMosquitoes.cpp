#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

const int maxN = 2e5 + 1;
const int maxD = 1e9 + 1;

ll frogPosition[maxN];
ll tongueLenght[maxN];
set<pairLL> segmentL, segmentR, notEatenMosq;

ll posMosq[maxN];
ll sizeMosq[maxN];
int eatenMosqPerFrog[maxN]; // eatenMosqPerFrog[i] - How many mosquitoes the i-th frog has eaten 

void print()
{
    set<pairLL>::iterator itr;
    for (itr = segmentL.begin(); itr != segmentL.end(); ++itr) 
    {
        cout << itr->first <<" "<< itr->second << ",";
    }
}


// erase all the frogs whose range (pos, pos + tongue lenght) is included in range of a frog on the left 
void tryErase(int id)
{
    if(segmentL.find(make_pair(frogPosition[id], id)) == segmentL.end()) return; //segmentL.end() biggest in first then in secondd

    while(1)
    {
        auto it = segmentL.lower_bound(make_pair(frogPosition[id] + 1, -1));
        if(it == segmentL.end()) break;
        
        int p = it->second;
        if(frogPosition[id] + tongueLenght[id] < frogPosition[p] + tongueLenght[p]) break;

        segmentL.erase(it);
        segmentR.erase(make_pair(frogPosition[p] + tongueLenght[p], p));
    }
}

void tryEat(int id)
{
    while(1)
    {
        auto it = notEatenMosq.lower_bound(make_pair(frogPosition[id] + tongueLenght[id] + 1, -1));
        if(it == notEatenMosq.begin()) break;
        it--;
        if(it->first < frogPosition[id]) break;
        tongueLenght[id] += sizeMosq[it->second];
        eatenMosqPerFrog[id]++;
        notEatenMosq.erase(it);
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld", &frogPosition[i], &tongueLenght[i]);
        segmentL.insert(make_pair(frogPosition[i], i));
        segmentR.insert(make_pair(frogPosition[i] + tongueLenght[i], i));
    }

    for (int i = 0; i < n; i++) tryErase(i);
    // print();

    for(int i = 0 ; i < m; i++)
    {
        scanf("%lld %lld", &posMosq[i], &sizeMosq[i]);

        auto it = segmentR.lower_bound(make_pair(posMosq[i], -1));
        if(it == segmentR.end() || frogPosition[it->second] > posMosq[i])
        {
            notEatenMosq.insert(make_pair(posMosq[i], i));
            continue;
        }
        
        int id = it->second;
        segmentR.erase(make_pair(frogPosition[id] + tongueLenght[id], id));
        tongueLenght[id] += sizeMosq[i];
        eatenMosqPerFrog[id]++;

        tryEat(id); // after having increased the size of the tongue, check if it's possible to eat not eaten mosquitoes so far

        segmentR.insert(make_pair(frogPosition[id] + tongueLenght[id], id));
        tryErase(id);
    }

    for(int i = 0; i < n; i++) printf("%d %lld\n", eatenMosqPerFrog[i], tongueLenght[i]);

    
    return 0;
}
