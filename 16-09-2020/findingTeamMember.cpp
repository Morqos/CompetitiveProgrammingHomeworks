#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
 
const int MOD=1e9+7;
const int INF=1e9+7;

const int maxN = 400 + 5;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    scanf("%d", &N);

    int nPeople = 2*N;
    int size = nPeople*(nPeople-1)/2; // how many possible couples we can have (combinatorics)
    vector<pair<int,pairIntInt>> strenght(size); // strenght[i]: (a, b, c) -> a = strenght of team of person b and c, b = person, c = person
    int c = 0;
    for(int i = 2 ; i <= nPeople; i++)
    {
        for(int j = 1; j < i; j++)
        {
            scanf("%d", &strenght[c].first);
            strenght[c].second.first = i;
            strenght[c].second.second = j;
            c++;
        }
    }

    if(nPeople==2) { printf("2 1"); exit(0); }

    // sort for strenght
    sort(strenght.begin(), strenght.end(), [](const pair<int,pairIntInt>& lhs, const pair<int,pairIntInt>& rhs)
    {
        return lhs.first > rhs.first;
    });

    // The first couples are the ones who can be formed, as long as they don't override other couples
    vector<int> ans(nPeople+1, -1);
    for(int i = 0; i < size; i++)
    {
        int p1 = strenght[i].second.first;
        int p2 = strenght[i].second.second;
        if(ans[p1] == -1 && ans[p2] == -1)
        {
            ans[p1] = p2;
            ans[p2] = p1;
        }
    }
    
    for(int i = 1; i <= nPeople; i++)
    {
        cout<<ans[i]<<" ";
    }

    return 0;
}
