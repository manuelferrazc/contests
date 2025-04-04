#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

map<pair<int,int>,long double> dp;
string a,b;

long double ddp(int pos, int n) {
    if(dp.count(make_pair(pos,n))) 
        return dp.at(make_pair(pos,n));
    if(n==0) {
        if(pos==0) return 1;
        else return 0;
    }

    if(b[n-1]=='+') 
        dp.insert(make_pair(make_pair(pos,n),ddp(pos-1,n-1)));
    else if(b[n-1]=='-') {
        dp.insert(make_pair(make_pair(pos,n),ddp(pos+1,n-1)));
    } else {
        dp.insert(make_pair(make_pair(pos,n),0.5*(ddp(pos-1,n-1)+ddp(pos+1,n-1))));
    }
    return dp[{pos,n}];
}

void solve() {
    int p=0;
    cin >> a >> b;
    for(auto i:a) {
        if(i=='+') p++;
        else p--;
    }

    cout << ddp(p,(int)a.size()) << '\n';
}

int main() { _
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
