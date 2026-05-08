#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;
typedef long double ld;
#define int ll

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld EPS = 1e-9, euler = 2.71828182845905, pi = 3.14159265358979;

vector<int> fact(21);

int comb(int a, int b){
    return fact[a]/fact[b]/fact[a-b];
}

ld calc(string s, ld A, ld C, ld P){
    int t = s.size(), v = 0, c = 0;
    for(int i = 0; i < t; i++){
        char ch = tolower(s[i]);
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u') v++;
        else c++;
    }

    ld tot = 0;
    for(int k = 1; k <= t; k++){
        tot += pow(P, 1.0/ld(k))*(k&1 ? -1 : 1);
    }
    tot = fabs(tot);

    tot *= comb(max(v, c)+1, min(v, c)-1);

    tot *= (ceil(sqrt(pow(v, euler)+pow(c, euler))) / floor(pi+log1p(A*C)));

    return tot;
}

int32_t main() { _
    fact[0] = 1;
    for(int i = 1; i <= 20; i++) fact[i] = fact[i-1]*i;

    int n; cin >> n;
    vector<tuple<string, ld, ld, ld>> v;
    for(int i = 0; i < n; i++){
        string s; ld a, c, p; cin >> s >> a >> c >> p;
        v.emplace_back(s, a, c, p);
    }

    sort(v.begin(), v.end(), [&](tuple<string, ld, ld, ld> a, tuple<string, ld, ld, ld> b){
        auto [sa, aa, ca, pa] = a;
        auto [sb, ab, cb, pb] = b;

        ld ansa = calc(sa, aa, ca, pa), ansb = calc(sb, ab, cb, pb);
        if(abs(ansa-ansb) < EPS) return ansa-ansb < -EPS;
        return sa < sb;
    });

    for(int i = 0; i < n; i++){
        auto [s, a, c, p] = v[i];
        ld ans = calc(s, a, c, p);
        int res = ans, sz = to_string(res).size();
        cout << s;
        for(int j = 0; j < sz; j++) cout << "!";
        cout << endl;
    }

    return 0;
}