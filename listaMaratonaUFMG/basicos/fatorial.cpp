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

ll dig[] = {1,1,2,6,4,2,2,4,2,8};

ll lastNon0Digit(ll n) {
    if(n<10) return dig[n];
    if(((n/10)%10)%2 == 0) return (6*lastNon0Digit(n/5)*dig[n%10]) % 10;
    else return (4*lastNon0Digit(n/5)*dig[n%10]) % 10;
}

void solve(ll n, ll inst) {
    cout << "Instancia " << inst << "\n" << lastNon0Digit(n) << "\n\n";
}

int main() { _
    ull in, instancia = 1;

    while(cin >> in) solve(in,instancia++);

    return 0;
}