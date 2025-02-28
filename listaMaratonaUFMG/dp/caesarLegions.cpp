#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

#define MOD 100000000

int main() { _
    ull foot, horse, maxf, maxh;
    cin >> foot >> horse >> maxf >> maxh;

    vector<vector<vector<vector<ull>>>>
        dp(foot+1,vector<vector<vector<ull>>>(horse+1,vector<vector<ull>>(maxf+1,vector<ull>(maxh+1,0))));

    for(ull i=1;i<=min(foot,maxf);i++) dp[i][0][i][0] = 1;
    for(ull i=1;i<=min(horse,maxh);i++) dp[0][i][0][i] = 1;
        
    for(ull f=1;f<=foot;f++) {
        for(ull h=1;h   <=horse;h++) {
            for(ull sf=1;sf<=maxf and sf<=f;sf++)  // caso iniciar sequencia de cavalo
                dp[f][h][0][1]=(dp[f][h][0][1]+dp[f][h-1][sf][0])%MOD;
                
            for(ull sh=1;sh<=maxh and sh<=h;sh++) // caso iniciar sequencia de foot
                dp[f][h][1][0]=(dp[f][h][1][0]+dp[f-1][h][0][sh])%MOD;

            for(ull sh=2;sh<=maxh and sh<=h;sh++) // caso aumentar sequencia de cavalo já existente
                dp[f][h][0][sh] = dp[f][h-1][0][sh-1];

            for(ull sf=2;sf<=maxf and sf<=f;sf++) // caso aumentar sequencia de foot ja existente
                dp[f][h][sf][0] = dp[f-1][h][sf-1][0];
        }
    }

    ull ans = 0;
    for(ull i=1;i<=maxf;i++) ans = (ans+dp[foot][horse][i][0])%MOD;
    for(ull i=1;i<=maxh;i++) ans = (ans+dp[foot][horse][0][i])%MOD;

    cout << ans << '\n';
    return 0;
}