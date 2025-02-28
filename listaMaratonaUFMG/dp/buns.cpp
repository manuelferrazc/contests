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

int solve(vi &p, vi &l,int mas) {
    vvi dp(p.size(),vi(mas+1,0));

    for(int i=1;i<(int)p.size();i++) {
        for(int c=1;c<=mas;c++) {
            if(p[i]<=c) dp[i][c] = max(dp[i-1][c], dp[i-1][c-p[i]]+l[i]);
            else dp[i][c] = dp[i-1][c];
        }
    }

    return dp.back().back();
}

int main() { _
    int gmassa, qstuff, cus0, luc0;
    cin >> gmassa >> qstuff >> cus0 >> luc0;

    vi qtd(qstuff+1), cuss(qstuff+1), cusm(qstuff+1), luc(qstuff+1);
    qtd[0] = 0;
    cuss[0] = 0;
    cusm[0] = cus0;
    luc[0] = luc0;

    for(int i=1;i<=qstuff;i++) cin >> qtd[i] >> cuss[i] >> cusm[i] >> luc[i];

    vi p,l;
    p.push_back(INT_MAX);
    l.push_back(INT_MIN);
    for(int s=0;s<=qstuff;s++) {
        int m = gmassa;
        while(m>=cusm[s] and cuss[s]<=qtd[s]) {
            m-=cusm[s];
            qtd[s]-=cuss[s];
            p.push_back(cusm[s]);
            l.push_back(luc[s]);
        }
    }

    cout << solve(p,l,gmassa) << '\n';

    return 0;
}