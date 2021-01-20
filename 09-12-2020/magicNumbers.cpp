#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 1e9 + 5;

string s;

int checkS()
{
    int sSize = s.size();
    
    if(s[0] != '1') return 0;
    
    for(int i = 1; i < sSize; i++) if(s[i] != '1' && s[i] != '4') return 0;

    for(int i = 0; i < sSize - 3; i++)
    {
        if(s[i] != '1' && s[i] != '4') return 0;
        if(s[i + 1] != '1' && s[i + 2] != '1' && s[i + 3] != '1') return 0;
    }

    return 1;
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cin >> s;

    cout << (checkS() ? "YES" : "NO") << endl;

    return 0;
}
